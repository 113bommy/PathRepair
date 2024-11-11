#include <bits/stdc++.h>
using namespace std;
template <class T>
T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
void printc(T c) {
  for (auto const& v : c) std::cout << v << ' ';
  cout << endl;
}
const long long LL_MAX_INF = std::numeric_limits<long long>::max();
const long long LL_MIN_INF = std::numeric_limits<long long>::min();
void solution();
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solution();
  }
  return 0;
}
void solution() {
  long long n;
  cin >> n;
  long long ans = n / 2;
  cout << ans << endl;
}
