#include <bits/stdc++.h>
using namespace std;
const long long int MAXN = 2 * 1e5 + 10;
long long int gcd(long long int a, long long int b) {
  return b ? gcd(b, a % b) : a;
}
long long int lcm(long long int a, long long int b) {
  return a / gcd(a, b) * b;
}
long long int binpow(long long int a, long long int b, long long int r) {
  a %= r;
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % r;
    a = (a * a) % r;
    b >>= 1;
  }
  return res;
}
bool is_prime(long long int n) {
  if (n == 0 || n == 1) return 0;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
int main() {
  string s;
  cin >> s;
  long long int n = s.length();
  long long int cnt = 1;
  if (n == 1 || n == 2 || n == 3) {
    cout << "YES" << endl << s;
    return 0;
  }
  vector<long long int> v;
  v.push_back(1);
  for (int i = n / 2 + 1; i <= n; i++) {
    if (is_prime(i)) {
      cnt++;
      v.push_back(i);
    }
  }
  cnt = n - cnt;
  long long int a[26];
  long long int i;
  for (i = 0; i < 26; i++) a[i] = 0;
  for (i = 0; i < n; i++) {
    a[s[i] - 'a']++;
  }
  bool po = 0;
  for (i = 0; i < 26; i++) {
    if (a[i] >= cnt) {
      po = 1;
      break;
    }
  }
  long long int j;
  for (j = 0; j < n; j++) s[j] = '?';
  if (!po)
    cout << "NO" << endl;
  else {
    for (j = 2; j <= n; j++) {
      if (j <= n / 2 || !is_prime(j)) {
        s[j - 1] = 'a' + i;
        a[i]--;
      }
    }
    for (j = 0; j < n; j++) {
      if (s[j] == '?') {
        for (i = 0; i < 26; i++) {
          if (a[i] > 0) {
            s[j] = 'a' + i;
            a[i]--;
            break;
          }
        }
      }
    }
    cout << "YES" << endl << s << endl;
  }
  return 0;
}
