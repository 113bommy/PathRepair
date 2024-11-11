#include <bits/stdc++.h>
using namespace std;
inline void pisz(int n) { printf("%d\n", n); }
template <typename T, typename TT>
ostream& operator<<(ostream& s, pair<T, TT> t) {
  return s << "(" << t.first << "," << t.second << ")";
}
template <typename T>
ostream& operator<<(ostream& s, vector<T> t) {
  for (int(i) = 0; (i) < (((int)((t).size()))); ++(i)) s << t[i] << " ";
  return s;
}
int a[100007], b[100007], dp[100007][306];
vector<int> occ[100007];
int main() {
  int(n), (m);
  scanf("%d %d", &(n), &(m));
  int(s), (e);
  scanf("%d %d", &(s), &(e));
  for (int(i) = 1; (i) <= (n); ++(i)) scanf("%d", a + i);
  for (int(j) = 1; (j) <= (m); ++(j)) scanf("%d", b + j);
  for (int(j) = 1; (j) <= (m); ++(j)) occ[b[j]].push_back(j);
  for (int(x) = (1); (x) <= (100000); ++x) occ[x].push_back(1001001001 + 5);
  dp[0][0] = 0;
  for (int(k) = (1); (k) <= (300); ++k) dp[0][k] = 1001001001;
  int best = 0;
  for (int(i) = (1); (i) <= (n); ++i) {
    dp[i][0] = 0;
    for (int(k) = (1); (k) <= (300); ++k) {
      dp[i][k] = min(
          dp[i - 1][k],
          *upper_bound(occ[a[i]].begin(), occ[a[i]].end(), dp[i - 1][k - 1]));
    }
    for (int(k) = (0); (k) <= (300); ++k)
      if (dp[i][k] != 1001001001) {
        if (s >= 1LL * e * k + i + dp[i][k]) (best) = max((best), (k));
        ;
      }
  }
  pisz(best);
}
