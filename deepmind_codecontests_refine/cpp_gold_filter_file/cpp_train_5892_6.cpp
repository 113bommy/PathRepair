#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  long long int c = power(a, b / 2);
  if (b % 2 == 0) return ((c % 1000000007) * (c % 1000000007)) % 1000000007;
  return ((((c % 1000000007) * (c % 1000000007)) % 1000000007) *
          (a % 1000000007)) %
         1000000007;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n, k, t, c = 0, i, j, m, cs = 0;
  t = 1;
  string s;
  while (t--) {
    cin >> n;
    long long int a[n];
    vector<long long int> v;
    for (i = 0; i < n; i++) {
      cin >> k;
      if (k % 2) {
        v.push_back(k);
        if (k > 0) c++;
      } else if (k > 0)
        cs += k;
    }
    sort((v).begin(), (v).end(), greater<long long int>());
    for (i = 0; i < c; i++) cs += v[i];
    if (c % 2)
      cout << cs;
    else {
      if (c < (long long int)v.size() && c > 0)
        cs = max(cs - v[c - 1], cs + v[c]);
      else if (c > 0)
        cs = cs - v[c - 1];
      else
        cs += v[c];
      cout << cs;
    }
    if (t != 0) cout << "\n";
  }
  return 0;
}
