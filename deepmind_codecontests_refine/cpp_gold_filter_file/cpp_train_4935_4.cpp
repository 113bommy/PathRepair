#include <bits/stdc++.h>
using namespace std;
const int N = 2013;
const int MOD = 1e9 + 7;
char p[1000005], second[205];
string getSuff(int n, int m, bool& error) {
  error = false;
  string ans;
  for (int i = 0; i < n; ++i) ans += "0";
  int i, j;
  for (i = n - 1, j = m - 1; i >= 0 && j >= 0; --i)
    if (p[i] == second[j]) ans[i] = '1', --j;
  if (j != -1)
    error = true;
  else
    return ans;
}
int k, n, m;
int main() {
  gets(p);
  gets(second);
  cin >> k;
  n = strlen(p);
  m = strlen(second);
  string minLex;
  for (int i = 1; i <= k + 1; ++i) minLex += "1";
  int rboud = min(m, k), cntIn = n / k, R = n % k;
  for (int d = 1; d <= rboud && cntIn * d <= m; ++d) {
    string cans;
    for (int i = 1; i <= k; ++i) cans += "0";
    {
      int r = d - 1, i = min(n - 1, k - 1);
      for (; i >= 0 && r >= 0; --i) {
        int l1 = m / d + (r < m % d);
        int l2 = cntIn + (i < R);
        if (l1 != l2) continue;
        bool diff = false;
        for (int e = 0; e < l1 && !diff; ++e)
          diff = second[r + e * d] != p[i + e * k];
        if (diff) continue;
        cans[i] = '1';
        --r;
      }
      if (r == -1) minLex = min(minLex, cans);
    }
  }
  if (minLex.size() > k)
    cout << 0;
  else {
    cout << minLex;
    for (int i = 1; i <= k - minLex.size(); ++i) printf("0");
  }
  return 0;
}
