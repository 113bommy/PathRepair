#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 100;
int is_p[MAXN], p[MAXN], gdb[MAXN][2], a[MAXN], pla[MAXN];
int ans[MAXN * 5][2], ans_len;
int n, len;
void swap(int i, int j) {
  ans[ans_len][0] = i;
  ans[ans_len][1] = j;
  ans_len++;
  int t = a[i];
  a[i] = a[j];
  a[j] = t;
  pla[a[i]] = i;
  pla[a[j]] = j;
}
int main() {
  memset(is_p, 0, sizeof(is_p));
  for (int i = 2; i * i < MAXN; i++)
    for (int j = 2; i * j < MAXN; j++) is_p[i * j] = 1;
  len = 0;
  for (int i = 2; i < MAXN; i++)
    if (is_p[i] == 0) p[len++] = i;
  for (int i = 4; i < MAXN; i += 2) {
    for (int j = 0; j < len; j++)
      if (is_p[i - p[j]] == 0) {
        gdb[i][0] = p[j];
        gdb[i][1] = i - p[j];
        break;
      }
  }
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
    pla[a[i]] = i;
  }
  ans_len = 0;
  for (int i = 0; i < n; i++) {
    int x = pla[i] - i;
    if (x == 0) continue;
    if (x == 1) {
      swap(i, i + 1);
      continue;
    }
    if (x == 2) {
      swap(i, i + 2);
      continue;
    }
    if (x == 3) {
      swap(i + 1, i + 3);
      swap(i, i + 1);
      continue;
    }
    if (x % 2 == 0) {
      swap(i + x - 1, i + x);
      x--;
    }
    if (x % 2 == 1) {
      int p1 = gdb[x + 1][0];
      swap(i + p1 - 1, i + x);
      swap(i, i + p1 - 1);
    }
  }
  cout << ans_len << endl;
  for (int i = 0; i < ans_len; i++)
    cout << ans[i][0] + 1 << ' ' << ans[i][1] + 1 << endl;
}
