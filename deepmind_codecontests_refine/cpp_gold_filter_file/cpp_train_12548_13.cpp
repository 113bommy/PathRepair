#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename C>
ostream& operator<<(ostream& os, const vector<C>& v) {
  for (__typeof((v).begin()) __it = (v).begin(); __it != (v).end(); __it++)
    os << *(__it) << ' ';
  return os;
}
const int inf = 0x3f3f3f3f;
const long long inf64 = 0x3f3f3f3f3f3f3f3fLL;
const double eps = 1e-5;
int main() {
  vector<int> primes;
  vector<unsigned long long> usage;
  unsigned long long mul = 1;
  for (int i = 3; i < 24; i += 2) {
    bool ok = true;
    for (int j = 0; j < (int((primes).size())); j++)
      if (i % primes[j] == 0) {
        ok = false;
        break;
      }
    if (ok) {
      {
        cerr << "i"
             << " = " << (i) << endl;
      };
      {
        cerr << "mul"
             << " = " << (mul) << endl;
      };
      primes.push_back(i);
      usage.push_back(i);
      mul *= i;
      {
        cerr << "primes.size()"
             << " = " << (primes.size()) << endl;
      };
    }
  }
  int n;
  cin >> n;
  if (n == 2) {
    puts("-1");
    return 0;
  }
  int cur = 0;
  for (int i = 0; i < n - 1; i++, cur++) {
    for (;; cur++) {
      if (cur == (int((usage).size()))) cur = 0;
      if (usage[cur] > 0) break;
    }
    cout << usage[cur] * 2 << endl;
    usage[cur] *= primes[cur];
    if (usage[cur] > 1000000000) usage[cur] = -1;
  }
  cout << mul << endl;
  return 0;
}
