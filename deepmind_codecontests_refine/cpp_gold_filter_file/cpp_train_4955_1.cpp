#include <bits/stdc++.h>
using namespace std;
long long int mod = 998244353;
const double PI = acos(-1), ebs = 1e-8;
bool visited[10010][3];
bool valid(int i, int j) {
  int n;
  int m;
  if (i < n || j < m) return true;
  return false;
}
int sum_of_dg(long long int x) {
  long long int sum = 0;
  while (x) {
    sum += x % 10;
    x /= 10;
  }
  return sum;
}
long long int power(long long int a, long long int n) {
  if (n == 0) return 1;
  long long int res = power(a, n / 2);
  res *= res;
  if (n % 2 == 1) res *= a;
  return res;
}
long long int gcd(long long int x, long long int y) {
  return y ? gcd(y, x % y) : x;
}
long long int fac(long long int x) { return (x ? x * fac(x - 1) : 1); }
long long int lcm(long long int x, long long int y) {
  return (x * y) / gcd(x, y);
}
string x, y;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  cin >> x;
  cin >> y;
  vector<char> v;
  for (int i = 0; i < x.size(); i++) {
    if (x[i] == y[i])
      v.push_back('z');
    else if (x[i] < y[i]) {
      cout << "-1";
      return 0;
    } else {
      v.push_back(y[i]);
    }
  }
  for (int i = 0; i < v.size(); i++) cout << v[i];
  return 0;
}
