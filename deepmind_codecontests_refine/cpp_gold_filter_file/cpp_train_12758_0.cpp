#include <bits/stdc++.h>
using namespace std;
long long binomialCoeff(long long n, long long k) {
  long long res = 1;
  if (k > n - k) k = n - k;
  for (long long i = 0; i < k; ++i) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}
long long M = 1e9 + 7;
long long mods(long long a, long long b) {
  a = a % M;
  b = b % M;
  return (a + b) % M;
}
long long modp(long long a, long long b) {
  a = a % M;
  b = b % M;
  return (a * b) % M;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  int n = s.length();
  int r = -1;
  int j = 0;
  int p = -1;
  while (j < n) {
    if (s[j] == 'a')
      p = j;
    else
      break;
    j++;
  }
  for (int i = p + 1; i < n; i++) {
    if (s[i] != 'a')
      r = i;
    else
      break;
  }
  if (r == -1) {
    int k = s[n - 1] - 'a';
    if (k == 0)
      k = k + 25;
    else
      k = k - 1;
    s[n - 1] = k + 'a';
    cout << s << endl;
  } else {
    for (int i = p + 1; i <= r; i++) {
      int k = s[i] - 'a' - 1;
      s[i] = k + 'a';
    }
    cout << s << endl;
  }
}
