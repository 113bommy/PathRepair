#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long m;
  long long n, k = 0, k1 = 0, k0 = 0, sm = 0, mn = 1e5, sm_original = 0, f = 0,
               k2 = 0, t, mx = -1;
  string s;
  cin >> n;
  cin >> s;
  for (long long i = 0; i < s.size(); i++)
    if (s[i] == '8') k++;
  n = s.size() / 11;
  cout << min(n, k);
}
