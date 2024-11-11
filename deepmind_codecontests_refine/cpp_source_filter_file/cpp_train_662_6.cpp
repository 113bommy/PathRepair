#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T abs(T t) {
  return t < 0 ? -t : t;
}
const long long modn = 1000000007;
inline long long mod(long long x) { return x % modn; }
const int N = 100005;
const long long oo = 1000000000000000;
int n, m, p;
long long a[N], d[N], sm[N];
long long dp[110][N];
vector<pair<long long, int> > st;
long long xcont(int l, int k, int i) {
  long long v1 = sm[l] - sm[k];
  long long v2 = dp[i - 1][l] - dp[i - 1][k];
  long long v3 = l - k;
  return (long long)ceil((double)(v1 + v2) / (double)v3);
}
int main() {
  int i, j, k, x, h, t;
  scanf("%d%d%d", &n, &m, &p);
  for (i = 1; i <= n - 1; i++) {
    scanf("%d", &x);
    d[i + 1] = d[i] + x;
  }
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &h, &t);
    a[i] = t - d[h];
  }
  sort(a, a + m + 1);
  for (i = 1; i <= m; i++) sm[i] = sm[i - 1] + a[i];
  for (i = 1; i <= m; i++) dp[1][i] = (i - 1) * a[i] - sm[i - 1];
  for (i = 2; i <= p; i++) {
    st.clear();
    st.push_back(pair<long long, int>(-oo, 0));
    for (j = 1; j <= m; j++) {
      int l = 0, r = st.size() - 1;
      while (l < r) {
        int m = (l + r + 1) / 2;
        if (st[m].first <= a[j])
          l = m;
        else
          r = m - 1;
      }
      k = st[l].second;
      dp[i][j] = a[j] * (j - k) - sm[j] + sm[k] + dp[i - 1][k];
      while (!st.empty() && xcont(st.back().second, j, i) <= st.back().first)
        st.pop_back();
      st.push_back(pair<long long, int>(xcont(st.back().second, j, i), j));
    }
  }
  cout << dp[p][m] << endl;
  return 0;
}
