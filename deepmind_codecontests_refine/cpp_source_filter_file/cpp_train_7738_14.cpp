#include <bits/stdc++.h>
using namespace std;
long long conversion(string p) {
  long long o;
  o = atol(p.c_str());
  return o;
}
string toString(int h) {
  stringstream ss;
  ss << h;
  return ss.str();
}
long long gcd(long long a, long long b) { return (b == 0 ? a : gcd(b, a % b)); }
int lcm(int a, int b) { return (a * (b / gcd(a, b))); }
vector<int> P;
bool v[1005];
bool esPrimo(int n) {
  if (n <= 1) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  for (int i = 3; i * i <= n; i += 2)
    if (n % i == 0) return false;
  return true;
}
void sieve() {
  memset(v, true, sizeof v);
  for (int i = 2; i <= 1000; i++) {
    if (v[i]) {
      for (int j = i * i; j <= 1000; j += i) v[j] = false;
      P.push_back(i);
    }
  }
}
int main() {
  int n, k, res = 0;
  cin >> n >> k;
  set<int> S;
  sieve();
  for (int i = 0; i < P.size() - 1; i++) {
    if ((P[i] + P[i + 1] + 1) <= n && esPrimo(P[i] + P[i + 1] + 1))
      S.insert(P[i] + P[i + 1] + 1);
  }
  if (S.size() >= n)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
