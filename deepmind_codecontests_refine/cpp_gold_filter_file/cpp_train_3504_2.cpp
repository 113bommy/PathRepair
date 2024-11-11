#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T rd() {
  T nmb = 0;
  int sgn = 0;
  char chr = getchar();
  while (!isdigit(chr)) {
    if (chr == '-') sgn = 1;
    chr = getchar();
  }
  while (isdigit(chr)) {
    nmb = (nmb << 3) + (nmb << 1) + chr - '0';
    chr = getchar();
  }
  return sgn ? -nmb : nmb;
}
template <typename T>
void wt(T nmb) {
  if (nmb > 9) wt(nmb / 10);
  putchar(nmb % 10 + '0');
}
template <typename T>
inline void cmax(T &x, T y) {
  x = x > y ? x : y;
}
template <typename T>
inline void cmin(T &x, T y) {
  x = x < y ? x : y;
}
inline void proc_status() {
  ifstream t("/proc/self/status");
  cerr << string(istreambuf_iterator<char>(t), istreambuf_iterator<char>())
       << endl;
}
const int N = 1e5 + 10, K = 65;
vector<long long> vec[K];
long long ans[N];
int main() {
  int n = rd<int>();
  for (int i = 1; i <= n; ++i) {
    long long k = rd<long long>();
    for (int j = 60; ~j; --j)
      if (k & (1ll << j)) {
        vec[j].push_back(k);
        break;
      }
  }
  long long res = 0;
  for (int i = 1; i <= n; ++i) {
    int flg = 0;
    for (int j = 0; j <= 60; ++j) {
      if (!(res & (1ll << j)) && !vec[j].empty()) {
        res ^= vec[j][vec[j].size() - 1];
        ans[i] = vec[j][vec[j].size() - 1];
        vec[j].pop_back();
        flg = 1;
        break;
      }
    }
    if (!flg) return puts("No"), 0;
  }
  puts("Yes");
  for (int i = 1; i <= n; ++i) printf("%lld ", ans[i]);
  return 0;
}
