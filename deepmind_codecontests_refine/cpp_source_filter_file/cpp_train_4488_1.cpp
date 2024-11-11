#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, j, k, l, m, n, o, t, p, z = 0;
  string s, ans;
  cin >> n >> k >> s;
  long long ar[100];
  memset(ar, 0, sizeof ar);
  for (i = 0; i < n; i++) ar[s[i] - 64]++;
  long long mn = 100000;
  for (i = 1; i <= k; i++) mn = min(mn, ar[i]);
  if (mn == 100000) mn = 0;
  cout << mn * k << endl;
  return 0;
}
