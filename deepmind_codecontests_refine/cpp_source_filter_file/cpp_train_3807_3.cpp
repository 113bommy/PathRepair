#include <bits/stdc++.h>
using namespace std;
void prv(const vector<long long> &v) {
  long long n = v.size();
  for (long long i = 0; i < n; i++) cout << v[i] << " ";
  cout << "\n";
}
long long power(long long a, long long n, long long lelo) {
  if (n == 0) return 1;
  if (n == 1) return a;
  if (n == 2) return (a * a) % lelo;
  if (n % 2)
    return (a * power(a, n - 1, lelo)) % lelo;
  else
    return power(power(a, n / 2, lelo), 2, lelo) % lelo;
}
void swap(long long &a, long long &b) {
  long long tm = a;
  a = b;
  b = tm;
}
vector<string> split(const std::string &s, char delim) {
  vector<string> e;
  stringstream ss(s);
  string item;
  while (getline(ss, item, delim)) e.push_back(item);
  return e;
}
const long long N = 1e5 + 5;
bool chkp(long long x) {
  for (long long i = 2; i * i <= x; i++)
    if (x % i == 0) return 0;
  return 1;
}
void solve() {
  long long n;
  cin >> n;
  if (chkp(n)) {
    cout << 1;
    return;
  }
  if (n % 2 == 0)
    cout << 2;
  else {
    if (chkp(n - 3))
      cout << 2;
    else
      cout << 3;
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long double tt = clock();
  long long t = 1;
  for (long long(i) = (1); (i) < (t + 1); (i)++) {
    solve();
    cout << "\n";
  }
  return 0;
}
