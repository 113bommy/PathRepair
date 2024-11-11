#include <bits/stdc++.h>
using namespace std;
template <typename T>
std::ostream& operator<<(std::ostream& str, const std::vector<T>& v) {
  str << "[";
  for (auto n : v) str << n << ", ";
  str << "]";
  return str;
}
const int MOD = 1e9 + 7;
int main() {
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  long long t, a, b;
  cin >> t >> a >> b;
  if (t == 1 && a == 1 && b == 1) {
    cout << "inf" << endl;
    return 0;
  }
  int constant = (a == b);
  bool power = false;
  if (t == 1) {
    if (a == 1) {
      cout << 0 << endl;
      return 0;
    }
    long long apow = a * a;
    while (apow <= b) {
      if (apow == b) {
        power = true;
        break;
      }
      if (apow * a < apow) break;
      apow *= a;
    }
  }
  int match = false;
  if (a > 1 && (t > 1 || !power)) {
    long long tpow = 1;
    long long tsum = 0;
    while (b) {
      long long c = b % a;
      tsum += c * tpow;
      tpow *= t;
      b /= a;
    }
    match = (tsum == a);
  }
  cout << match + constant + power << endl;
}
