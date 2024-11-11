#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b, long long m) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % m;
    b /= 2;
    a = (a * a) % m;
  }
  return ans;
}
int main() {
  long long t = 1, b = 1;
  while (t--) {
    map<long long, long long> m[26];
    long long x[26];
    for (char i = 'a'; i <= 'z'; ++i) {
      cin >> x[i - 'a'];
    }
    string s;
    cin >> s;
    long long pre[s.size()];
    pre[0] = x[s[0] - 'a'];
    m[s[0] - 'a'][pre[0]]++;
    long long c = 0;
    for (long long int i = 1; i < s.size(); i++) {
      long long y = s[i] - 'a';
      c += m[y][pre[i - 1]];
      pre[i] = pre[i - 1] + x[y];
      m[y][pre[i]]++;
    }
    cout << c << "\n";
  }
  return 0;
}
