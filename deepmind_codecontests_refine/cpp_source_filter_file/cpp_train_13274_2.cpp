#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) {
  if (a > b) return a;
  return b;
}
long long min(long long a, long long b) { return a + b - max(a, b); }
long long mulmod(long long a, long long b, long long mod) {
  return ((a % 1000000007) * (b % 1000000007) % 1000000007);
}
long long mod(long long a, long long b) {
  if (a > b)
    return a - b;
  else
    return b - a;
}
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long get(long long a, long long b, long long c, long long d) {
  if (a == b && (c == 0 || d == 0)) return 0;
  long long ans = 1000000000000000000;
  for (long long i = 0; i < 11; i++)
    for (long long j = 0; j < 11; j++) {
      if ((b + (i * c + j * d)) % 10 == a && i + j - 1 >= 0)
        ans = min(ans, i + j - 1);
    }
  return ans;
}
string negs(string str) {
  string res;
  for (auto it : str) {
    if (it == '*')
      res.push_back('+');
    else
      res.push_back('*');
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long n;
  cin >> n;
  if (n == 1) {
    cout << '+';
    return 0;
  }
  vector<string> vec(1 << n);
  vec[0] = "++";
  vec[1] = "+*";
  long long cursize = 2;
  for (long long i = 0; i < n - 1; i++) {
    for (long long j = 0; j < cursize; j++) {
      vec[j + cursize] = vec[j];
      vec[j] = (vec[j] + vec[j]);
      vec[j + cursize] = (vec[j + cursize] + negs(vec[j + cursize]));
    }
    cursize *= 2;
  }
  for (long long i = 0; i < (1 << n); i++) cout << vec[i] << "\n";
}
