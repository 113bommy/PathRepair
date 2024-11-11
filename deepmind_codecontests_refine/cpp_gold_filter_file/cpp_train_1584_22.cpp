#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
using namespace std;
const double PI = acos(-1);
long long gcd() { return 0ll; }
template <typename T, typename... Args>
T gcd(T a, Args... args) {
  return __gcd(a, (__typeof(a))gcd(args...));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  long long l = n * 9, r = n * 8;
  cout << l << " " << r << "\n";
  return 0;
}
