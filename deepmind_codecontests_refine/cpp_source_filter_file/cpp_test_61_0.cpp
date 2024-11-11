#include <bits/stdc++.h>
using namespace std;
template <class T>
T read() {
  T re = 0;
  char c = getchar();
  bool negt = false;
  while (c < '0' || c > '9') negt |= (c == '-'), c = getchar();
  while (c >= '0' && c <= '9')
    re = (re << 1) + (re << 3) + c - '0', c = getchar();
  return negt ? -re : re;
}
const int N = 2e5 + 10;
int a[N], b[N];
long long cnt1[N], cnt2[N];
map<pair<int, int>, int> cnt3;
int n;
void solve() {
  long long ans = 0;
  n = read<int>();
  for (int i = 1; i <= n; i++) a[i] = read<int>(), b[i] = read<int>();
  for (int i = 1; i <= n; i++) cnt1[i] = cnt2[i] = 0;
  for (int i = 1; i <= n; i++)
    ++cnt1[a[i]], ++cnt2[b[i]], ++cnt3[make_pair(a[i], b[i])];
  long long add = 0;
  add += n * (n - 1) * (n - 2) / 6;
  for (int i = 1; i <= n; i++)
    if (cnt1[i] != 0) {
      add -= (cnt1[i] - 1) * cnt1[i] * (n - cnt1[i]) / 2;
      add -= (cnt1[i] - 2) * (cnt1[i] - 1) * cnt1[i] / 6;
    }
  add += n * (n - 1) * (n - 2) / 6;
  for (int i = 1; i <= n; i++)
    if (cnt2[i] != 0) {
      add -= (cnt2[i] - 1) * cnt2[i] * (n - cnt2[i]) / 2;
      add -= (cnt2[i] - 2) * (cnt2[i] - 1) * cnt2[i] / 6;
    }
  long long minus = n * (n - 1) * (n - 2) / 6;
  for (int i = 1; i <= n; i++) minus -= (cnt1[a[i]] - 1) * (cnt2[b[i]] - 1);
  minus -= add;
  printf("%lld\n", add + minus);
}
int main() {
  int T = read<int>();
  while (T--) {
    solve();
  }
  return 0;
}
