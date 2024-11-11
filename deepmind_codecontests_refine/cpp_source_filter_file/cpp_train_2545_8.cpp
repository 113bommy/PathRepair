#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long fct(long long a) {
  long long sum = 1;
  for (long long i = 2; i <= a; i++) sum *= i;
  return sum;
}
void fibo(long long a) {
  vector<int> v;
  v.push_back(0);
  cout << v[0] << " ";
  v.push_back(1);
  cout << v[1] << " ";
  for (long long z = 2; z <= a; z++) {
    v.push_back(v[z - 2] + v[z - 1]);
    cout << v[z - 2] + v[z - 1] << " ";
  }
}
bool isprime(long long a) {
  if (a == 2 || a == 3 || a == 5 || a == 7)
    return true;
  else if (a % 2 == 0)
    return false;
  else if (a == 1)
    return false;
  else {
    for (long long i = 3; i <= sqrt(a); i += 2)
      if (a % i == 0) return false;
    return true;
  }
}
bool isPallindrom(string s) {
  long long z = (s).length();
  for (long long i = 0; i < z / 2; i++)
    if (s[i] != s[z - i - 1]) return false;
  return true;
}
int main() {
  long long a, b, c, d;
  while (cin >> a >> b >> c >> d) {
    long long cnt = 0, temp = 0, sum = 0, ans = 0, res = 0, i, j;
    if (abs(a - c) == abs(b - d))
      cout << a << " " << d << " " << c << " " << b << endl;
    else if (a == c)
      cout << a + b - d << " " << b << " " << a + b - d << " " << d << endl;
    else if (b == d)
      cout << a << " " << b + a - d << " " << c << " " << d + a - c << endl;
    else
      puts("-1");
  }
}
