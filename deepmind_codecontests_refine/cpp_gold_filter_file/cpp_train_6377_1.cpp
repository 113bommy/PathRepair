#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")
using namespace std;
string vow = "aeiou";
string VOW = "AEIOU";
const int NN = 100000 * 2 + 42;
char buf[NN];
int a[NN];
pair<int, int> tmp[NN];
int t[4 * NN];
int n, N;
int ans = -1;
int cnt = 0;
void Set(int ind, int val) {
  t[ind += N - 1] = val;
  for (; ind > 0; --ind >>= 1)
    t[(ind - 1) >> 1] = max(t[ind], t[ind + (ind & 1 ? 1 : -1)]);
}
int Max(int l, int r) {
  if (l < 0) l = 0;
  int R = t[r += N - 1];
  int L = t[l += N - 1];
  while (l + 1 < r) {
    if (l & 1) L = max(L, t[l + 1]);
    if (~r & 1) R = max(R, t[r - 1]);
    --r >>= 1;
    --l >>= 1;
  }
  return max(R, L);
}
void init() {
  memset(t, -0x7F, sizeof(t));
  gets(buf);
  n = strlen(buf);
  for (int i = 0; i < n; i++)
    if (vow.find(buf[i]) != -1 || VOW.find(buf[i]) != -1)
      a[i] = -1;
    else
      a[i] = 2;
  tmp[0].first = a[0];
  tmp[0].second = 0;
  for (int i = 1; i < n; i++) {
    tmp[i].second = i;
    tmp[i].first = tmp[i - 1].first + a[i];
  }
  tmp[n].second = -1;
  tmp[n].first = 0;
  n++;
  sort(tmp, tmp + n);
  N = 1;
  while ((1 << N) < n) N++;
  N = (1 << N);
  for (int i = 0; i < N; i++)
    if (i < n)
      Set(i, tmp[i].second);
    else
      Set(i, -INT_MAX);
}
void solve() {
  for (int i = 0; i < n - 1; i++) {
    int imax = Max(i + 1, N - 1);
    if (tmp[i].second > imax) continue;
    if (imax - tmp[i].second < ans) continue;
    if (imax - tmp[i].second == ans)
      cnt++;
    else {
      ans = imax - tmp[i].second;
      cnt = 1;
    }
  }
  if (ans == -1)
    cout << "No solution";
  else
    cout << ans << " " << cnt;
}
int main() {
  init();
  solve();
  return 0;
}
