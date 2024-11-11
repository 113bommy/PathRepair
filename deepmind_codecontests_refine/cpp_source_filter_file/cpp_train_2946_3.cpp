#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int up[N * 4];
int dw[N * 4];
int laz[N * 4];
int c4[N * 4];
int c7[N * 4];
int n, m;
int a[N];
void upd(int v) {
  c4[v] = c4[v * 2] + c4[v * 2 + 1];
  c7[v] = c7[v * 2] + c7[v * 2 + 1];
  up[v] = max({up[v * 2] + c7[v * 2 + 1], c4[v * 2] + up[v * 2 + 1],
               c4[v * 2] + c7[v * 2 + 1]});
  dw[v] = max({dw[v * 2] + c4[v * 2 + 1], c7[v * 2] + dw[v * 2 + 1],
               c7[v * 2] + c4[v * 2 + 1]});
}
void fil(int v = 1, int s = 1, int e = n + 1) {
  if (e - s == 1) {
    if (a[s] == 7)
      c7[v] = 1;
    else
      c4[v] = 1;
    up[v] = dw[v] = 1;
    return;
  }
  fil(v * 2, s, ((s + e) / 2));
  fil(v * 2 + 1, ((s + e) / 2), e);
  upd(v);
}
void add(int l, int r, int v = 1, int s = 1, int e = n + 1) {
  if (r <= s || e <= l) return;
  if (l <= s && e <= r) {
    laz[v] ^= 1;
    swap(up[v], dw[v]);
    swap(c4[v], c7[v]);
    return;
  }
  if (laz[v]) {
    swap(up[v * 2], dw[v * 2]);
    swap(up[v * 2 + 1], dw[v * 2 + 1]);
    swap(c4[v * 2], c7[v * 2 + 1]);
    swap(c4[v * 2 + 1], c7[v * 2 + 1]);
    laz[v * 2] ^= 1;
    laz[v * 2 + 1] ^= 1;
    laz[v] = 0;
  }
  add(l, r, v * 2, s, ((s + e) / 2));
  add(l, r, v * 2 + 1, ((s + e) / 2), e);
  upd(v);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    char c;
    cin >> c;
    a[i] = c - '0';
  }
  fil();
  while (m--) {
    string s;
    cin >> s;
    if (s == "count")
      cout << up[1] << ' ';
    else {
      int l, r;
      cin >> l >> r;
      add(l, r + 1);
    }
  }
  return 0;
}
