#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long mpow(long long x, long long y, long long m) {
  long long t = (y ? mpow(x, y / 2, m) : -1);
  return (t == -1 ? 1 % m : ((t * t % m) * ((y % 2) ? x : 1)) % m);
}
long long n1, n2, p1, p2, m, n;
long long trueDiv(long long a, long long b) {
  long double tmp = (long double)a / (long double)b;
  long long tmpl = a / b;
  if (tmp != tmpl) return tmpl + 1;
  return tmpl;
}
void err(string s) {
  cout << s;
  exit(0);
}
long long norm(long long x) { return x < 0 ? 0 : x; }
bool comp(pair<long long, long long> a, pair<long long, long long> b) {
  return a.second > b.second;
}
long long d[5][5], ans[5];
vector<long long> kick(vector<long long> x, long long val) {
  vector<long long> ans;
  for (auto y : x) {
    if (y != val) ans.push_back(y);
  }
  return ans;
}
long long calc(vector<long long> v) {
  long long ans = 0;
  for (long long i = 0; i < (v.size() - 1); i++) {
    ans += d[v[i] - 1][v[i + 1] - 1];
  }
  return ans;
}
vector<vector<long long>> ways = {
    {1, 3, 2, 4, 5}, {1, 3, 4, 2, 5}, {1, 2, 3, 4, 5}, {1, 4, 3, 2, 5}};
vector<pair<long double, long double>> get(long double x, long double y) {
  vector<pair<long double, long double>> ans = {{x, y + 1.0}, {x + 1.0, y}};
  return ans;
}
long double in(pair<long double, long double> x) {
  return (long double)m * x.first - (long double)n * x.second;
}
long long arr[4][4];
void rotate() {
  long long tmp[4][4];
  for (long long i = 0; i < (4); i++) {
    for (long long j = 0; j < (4); j++) {
      tmp[i][j] = arr[i][j];
    }
  }
  for (long long j = 0; j < (4); j++) {
    for (long long i = (4) - 1; i >= 0; i--) {
      arr[j][3 - i] = tmp[i][j];
    }
  }
}
void print() {
  for (long long i = 0; i < (4); i++) {
    for (long long j = 0; j < (4); j++) {
      cout << arr[i][j] << " ";
    }
    cout << "\n";
  }
}
vector<long long> v;
bool f(long long a, long long b) { return a > b; }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  for (long long i = 0; i < (t); i++) {
    long long a, b;
    cin >> a >> b >> n;
    vector<long long> v = {a, b, (a ^ b)};
    n %= 3;
    cout << v[n] << "\n";
  }
}
