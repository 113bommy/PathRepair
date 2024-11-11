#include <bits/stdc++.h>
using namespace std;
const long long inf = 4e18;
const long long maxn = 310;
const long long mod = 1e9 + 7;
const long long MAX = 1010;
#pragma GCC Optimize("Ofast")
bool is[MAX][MAX];
vector<pair<long long, long long> > ans;
long long d[maxn];
long long t = 1;
void add(long long a, long long b) { is[a][b] = is[b][a] = 1; }
void build(long long l, long long r, long long neg) {
  if (l == r) {
    long long s = d[l] - neg;
    for (long long i = 0; i < (s + 1); i++) {
      for (long long j = 0; j < (s + 1); j++) {
        add(t + i, t + j);
      }
    }
    t += s + 1;
    return;
  }
  if (l + 1 == r) {
    long long s1 = d[l] - neg;
    long long s2 = d[r] - neg;
    for (long long i = 0; i < s1; i++) {
      for (long long j = 0; j < (s2 + 1); j++) {
        add(t + i, t + j);
      }
    }
    t += s2 + 1;
    return;
  }
  long long T0 = t;
  build(l + 1, r - 1, d[l] - neg);
  long long s1 = d[l] - neg;
  long long s2 = d[r] - neg;
  for (long long i = 0; i < s1; i++) {
    for (long long j = 0; j < (s2 + 1); j++) {
      add(i + t, (T0 + j));
    }
  }
  t += d[r] - d[r - 1] + d[l] - neg;
}
int main() {
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) cin >> d[i];
  build(0, n - 1, 0);
  for (long long i = 0; i < MAX; i++) {
    for (long long j = 0; j < MAX; j++) {
      if (i <= j) continue;
      if (is[i][j]) ans.push_back(make_pair(i, j));
    }
  }
  cout << (ans).size() << endl;
  for (long long i = 0; i < (ans).size(); i++)
    cout << ans[i].first << " " << ans[i].second << endl;
}
