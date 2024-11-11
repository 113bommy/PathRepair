#include <bits/stdc++.h>
using namespace std;
string tostr(int a) {
  stringstream ss;
  ss << a;
  string res;
  ss >> res;
  return res;
}
long long p = 1000000007;
long long power(long long a, long long exp) {
  if (exp == 0) return 1;
  if (exp == 1) return a % p;
  if (exp % 2 == 0) return power((a * a) % p, exp / 2) % p;
  return (a * power((a * a) % p, (exp - 1) / 2)) % p;
}
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<long long> seqorig(n, 0);
  for (int i = 0; i < n; i++) cin >> seqorig[i];
  if (n == 1) {
    cout << seqorig[0] << endl;
    return 0;
  }
  vector<long long> seq(n - n % 2, 0);
  if (n % 2 == 0)
    for (int i = 0; i < n; i++) seq[i] = seqorig[i];
  else {
    for (int i = 0; i < n - 1; i++) {
      seq[i] = seqorig[i] + seqorig[i + 1] * (1 - 2 * (i % 2));
    }
  }
  if (n % 2 == 1) n--;
  long long u = 0;
  long long v = 0;
  long long m = (n - 2) / 2;
  long long binom = 1;
  for (long long k = 0; k <= m; k++) {
    if (k != 0) {
      binom = (binom * (m - k + 1)) % p;
      binom = (binom * power(k, p - 2)) % p;
    }
    u = (u + binom * seq[2 * k]) % p;
    v = (v + binom * seq[2 * k + 1]) % p;
  }
  if (n % 4 == 0)
    cout << (u + p - v) % p << endl;
  else
    cout << (u + v) % p << endl;
  return 0;
}
