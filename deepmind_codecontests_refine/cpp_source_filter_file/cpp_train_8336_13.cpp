#include <bits/stdc++.h>
using namespace std;
long long power(long x, long n) {
  if (n == 0) return 1;
  if (n == 1) return x;
  long n2 = n / 2;
  long long po = power(x, n2);
  if (n % 2) return po * po * x;
  return po * po;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  a %= b;
  return gcd(b, a);
}
class CSummarizeToThePowerOfTwo {
 public:
  void solve(std::istream &cin, std::ostream &cout) {
    int n, i;
    cin >> n;
    set<long long> v;
    vector<long long> V;
    map<long long, int> M;
    long long x;
    for (i = 0; i < n; i++) cin >> x, v.insert(x), M[x]++;
    x = 1;
    while (x <= 1000000000) {
      V.push_back(x);
      x *= 2ll;
    }
    n = V.size();
    int c = 0;
    for (auto it : v) {
      for (i = 0; i < n; i++) {
        if (v.find(V[i] - it) != v.end()) {
          if (V[i] == 2 * it) {
            if (M[it] > 1) break;
          } else {
            break;
          }
        }
      }
      if (i == n) c += M[it];
    }
    cout << c << "\n";
  }
};
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  CSummarizeToThePowerOfTwo solver;
  std::istream &in(std::cin);
  std::ostream &out(std::cout);
  solver.solve(in, out);
  return 0;
}
