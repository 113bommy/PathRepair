#include <bits/stdc++.h>
using namespace std;
int c[256] = {};
long long powq(long long a, long long b) {
  if (b == 0) return 1;
  long long p = pow(a, b / 2);
  if (b % 2 == 0)
    return p * p % 1000000007;
  else
    return p * p % 1000000007 * a % 1000000007;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) c[s[i]]++;
  vector<char> t;
  int cou = max({c['A'], c['C'], c['G'], c['T']});
  if (c['A'] == cou) t.push_back('A');
  if (c['C'] == cou) t.push_back('C');
  if (c['G'] == cou) t.push_back('G');
  if (c['T'] == cou) t.push_back('T');
  cout << powq(t.size(), n) << endl;
}
