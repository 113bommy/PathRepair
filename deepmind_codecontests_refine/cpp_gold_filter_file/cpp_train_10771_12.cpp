#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:256000000")
int a, b, c, d;
vector<pair<int, int> > ans;
pair<int, int> ver[1 << 16];
vector<int> mas;
int fen[200000];
int m1[200000], m2[200000];
int x1[200000], x2[200000];
int n;
void add(int pos) {
  while (pos < n) {
    fen[pos]++;
    pos |= pos + 1;
  }
}
void add(int pos, int val) {
  while (pos < n) {
    fen[pos] += val;
    pos |= pos + 1;
  }
}
int sum(int pos) {
  int su = 0;
  while (pos >= 0) {
    su += fen[pos];
    pos &= pos + 1;
    pos--;
  }
  return su;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &m1[i]);
  for (int i = 0; i < n; ++i) scanf("%d", &m2[i]);
  for (int i = n - 1; i >= 0; --i) {
    x1[i] = sum(m1[i]);
    add(m1[i]);
  }
  memset(fen, 0, sizeof fen);
  for (int i = n - 1; i >= 0; --i) {
    x2[i] = sum(m2[i]);
    add(m2[i]);
  }
  int u = 0;
  memset(fen, 0, sizeof fen);
  for (int i = n - 1; i >= 0; --i) {
    int t = (u + x1[i] + x2[i]) / (n - i);
    x1[i] = (x1[i] + x2[i] + u) % (n - i);
    u = t;
  }
  for (int i = 0; i < n; ++i) add(i);
  for (int i = 0; i < n; ++i) {
    int l = 0, r = n - 1, mid, ans;
    while (l <= r) {
      mid = (l + r) >> 1;
      if (sum(mid) <= x1[i])
        l = mid + 1;
      else {
        r = mid - 1;
        ans = mid;
      }
    }
    cout << ans << ' ';
    add(ans, -1);
  }
  return 0;
}
