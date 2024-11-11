#include <bits/stdc++.h>
template <class T>
inline void rd(T &x) {
  char c = getchar();
  x = 0;
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
}
using namespace std;
const int N = 5e3 + 10;
const int M = 1e6 + 10;
int a[N], n, k, w[M];
bool use[M];
int judge(int mod) {
  memset(use, 0, sizeof(use));
  int t, tag = 0;
  for (int i = 0; i < n; i++) {
    if (!use[t = a[i] % mod])
      use[t] = 1;
    else
      tag++;
    if (tag > k) break;
  }
  if (tag <= k) return 1;
  return 0;
}
int main() {
  rd(n);
  rd(k);
  int r = 0;
  for (int i = 0; i < n; i++) rd(a[i]), r = max(r, a[i]);
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) w[abs(a[i] - a[j])]++;
  int l = max(1, n - k);
  r++;
  int kk = k * k / 2 + 1;
  while (1) {
    int ret = 0;
    for (int i = 1; i * l <= r; i++) ret += w[i * l];
    if (ret <= kk && judge(l)) {
      cout << l << endl;
      return 0;
    }
    l++;
  }
  return 0;
}
