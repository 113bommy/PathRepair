#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 5;
const int MAXN = 23;
const int off = 1 << 23;
int n, p, dp[off], piv[off];
int s[MAXN], l[MAXN], t[MAXN];
vector<int> ind;
bool cmp(const int &A, const int &B) { return s[A] < s[B]; }
int type[MAXN], sol[MAXN];
void rebuild(int i, int c) {
  if (!i) return;
  type[piv[i]] = c;
  sol[piv[i]] = dp[i] - t[piv[i]];
  rebuild(i ^ (1 << piv[i]), c);
}
int main() {
  cin >> n >> p;
  for (int i = 0; i < n; ++i) {
    ind.push_back(i);
    cin >> s[i] >> l[i] >> t[i];
  }
  s[n] = inf;
  ind.push_back(n);
  sort(ind.begin(), ind.end(), cmp);
  dp[0] = 1;
  for (int m = 1; m < (1 << n); ++m) {
    dp[m] = inf;
    for (int i = 0; i < n; ++i) {
      if (!((1 << i) & m) || dp[m ^ (1 << i)] == inf) continue;
      int v = dp[m ^ (1 << i)];
      int j1 = 0, j2 = 0;
      while (v + t[i] < s[i]) {
        while (s[ind[j1]] + l[ind[j1]] - 1 < v) {
          j1++;
        }
        while (!((1 << ind[j2]) & m) || s[ind[j2]] + l[ind[j2]] - 1 < v) {
          if (j2 == n) break;
          j2++;
        }
        if (v + t[i] < s[ind[j2]] && v < s[ind[j1]]) {
          dp[m] = min(dp[m], v + t[i]);
          assert(m > 0);
          if (dp[m] == v + t[i]) {
            piv[m] = i;
          }
          break;
        }
        v = s[ind[j1]] + l[ind[j1]];
      }
    }
  }
  for (int i = 0; i < (p - 1) * ((1 << n) - 1) + 1; ++i) {
    int j = ((1 << n) - 1) ^ i;
    if (max(dp[i], dp[j]) != inf) {
      cout << "YES\n";
      rebuild(i, 2);
      rebuild(j, 1);
      for (int k = 0; k < n; ++k) {
        cout << type[k] << " " << sol[k] << endl;
      }
      return 0;
    }
  }
  cout << "NO\n";
}
