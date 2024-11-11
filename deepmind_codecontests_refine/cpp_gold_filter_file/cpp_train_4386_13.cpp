#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e5 + 5;
signed main() {
  long long n;
  string s;
  cin >> n >> s;
  string a = "";
  bool f = 0;
  for (long long i = 0; i < n; i++) {
    if (i + 1 < n && s[i] <= s[i + 1] || f) a += s[i];
    if (i + 1 < n && s[i] > s[i + 1]) f = 1;
  }
  if (f && (long long)a.size() < n - 1) a += s[n - 1];
  cout << a;
}
