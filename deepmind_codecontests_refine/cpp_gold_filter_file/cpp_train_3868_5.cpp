#include <bits/stdc++.h>
using namespace std;
long long ans, a, b, p = 1, c, d, e, i, j, n;
string s, s1;
map<long long, long long> m;
vector<long long> v;
int main() {
  cin >> s;
  n = s.size();
  ans = pow(9, n - 1);
  for (int i = 0; i < n; i++) {
    long long o = p * pow(9, n - i - 1) * (s[i] - '1');
    ans = max(ans, o);
    p = p * (s[i] - '0');
  }
  cout << max(ans, p);
}
