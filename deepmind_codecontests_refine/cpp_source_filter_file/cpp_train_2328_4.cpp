#include <bits/stdc++.h>
static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;
template <class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;
int main() {
  int n, m, v;
  cin >> n >> m >> v;
  if (m < n - 1 || 2 + (n - 1LL) * (n - 2LL) / 2 < m) {
    puts("-1");
    return 0;
  }
  vector<int> ord(n);
  iota(ord.begin(), ord.end(), 1);
  swap(ord[1], ord[v - 1]);
  for (int i = 0; i + 1 < n; ++i) {
    printf("%d %d\n", ord[i], ord[i + 1]);
  }
  m -= n - 1;
  for (int i = 1; i < n; ++i) {
    for (int j = i + 2; j < n; ++j) {
      if (!m) return 0;
      printf("%d %d\n", ord[i], ord[j]);
      m--;
    }
  }
  return 0;
}
