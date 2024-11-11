#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long long MAXN = 1e6;
const long long POLTOS = 50;
const long long SOTKA = 100;
const long long P = 1e9 + 7;
const long double pi = acos(-1);
const long double eps = 1e-7;
const long double base = 1e9 + 7;
const long long M = 1e3;
long long n;
inline bool sum_of_digits(long long x) {
  long long sum = x;
  while (x) {
    sum += x % 10;
    x /= 10;
  }
  return sum == n;
}
vector<long long> v;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = n - 100; i <= 100; i++) {
    if (sum_of_digits(i)) v.push_back(i);
  }
  cout << v.size() << endl;
  sort(v.begin(), v.end());
  for (long long i = 0; i < v.size(); i++) cout << v[i] << endl;
  return 0;
}
