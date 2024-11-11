#include <bits/stdc++.h>
using namespace std;
long long fastexpo(long long base, long long expo, long long M) {
  long long ans = 1;
  while (expo > 0) {
    if (expo % 2) {
      ans *= base;
      ans %= M;
    }
    base *= base;
    base %= M;
    expo /= 2;
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  long long n = s.size();
  long long a, b;
  cin >> a >> b;
  vector<long long> v1, v2;
  long long num = 0;
  for (long long i = 0; i < s.size(); i++) {
    num = num * 10 + s[i] - '0';
    if (num % a == 0) {
      if (s[i + 1] != '0') v1.push_back(i);
    }
    num = num % a;
  }
  long long rem = 0;
  for (long long i = n - 1; i >= 0; i--) {
    long long r = fastexpo(10, n - 1 - i, b);
    r *= (s[i] - '0');
    r %= b;
    rem += r;
    rem %= b;
    if (rem == 0) v2.push_back(i);
  }
  reverse(v2.begin(), v2.end());
  for (long long i : v1) {
    if (binary_search(v2.begin(), v2.end(), i + 1)) {
      cout << "YES"
           << "\n";
      for (long long j = 0; j <= i; j++) cout << s[j];
      cout << "\n";
      for (long long j = i + 1; j < n; j++) cout << s[j];
      cout << "\n";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
