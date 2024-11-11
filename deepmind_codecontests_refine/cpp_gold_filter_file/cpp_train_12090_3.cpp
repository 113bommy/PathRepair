#include <bits/stdc++.h>
static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;
template <class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    cout << b / 2 << " " << b / 2 * 2 << "\n";
  }
  return 0;
}
