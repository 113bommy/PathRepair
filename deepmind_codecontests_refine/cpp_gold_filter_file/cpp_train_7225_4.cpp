#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long Count[1000000][26];
int main() {
  long long n, m;
  string x, y;
  cin >> n >> m >> x >> y;
  long long X = x.size(), Y = y.size();
  long long GCD = gcd(X, Y);
  for (int i = 0; i < x.size(); i++) Count[i % GCD][x[i] - 'a']++;
  long long LCM = X * Y / GCD;
  long long A = LCM;
  for (int i = 0; i < y.size(); i++) A -= Count[i % GCD][y[i] - 'a'];
  cout << A * (n * X / LCM);
}
