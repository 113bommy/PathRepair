#include <bits/stdc++.h>
const long long INF = 1000000000;
const long long N = 205;
const long long modi = 998244353;
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  vector<long long> a(n);
  vector<long long> b(m);
  string s1, s2;
  cin >> s1;
  cin >> s2;
  for (long long i = 0; i < n; i++) {
    a[i] = s1[i] - '0';
  }
  for (long long i = 0; i < m; i++) {
    b[i] = s2[i] - '0';
  }
  long long ans = 0;
  long long sum = 0;
  long long curr = 1;
  for (long long i = 0; i < m; i++) {
    if (i < n && a[n - i - 1] == 1) {
      sum = (sum + curr) % modi;
    }
    if (b[m - i - 1] == 1) {
      ans = (ans + sum) % modi;
    }
    curr = (curr * 2) % modi;
  }
  cout << ans << endl;
}
