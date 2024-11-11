#include <bits/stdc++.h>
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  std::cout << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  std::cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long i, j, n, m, k, cnt = 0, ans = 0, t = 1;
  cin >> n >> m;
  long long a[n][m];
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) cin >> a[i][j];
  long long xrank[n + 1][m + 1];
  long long yrank[n + 1][m + 1], xdist[n + 1], ydist[n + 1];
  for (i = 0; i < n; i++) {
    vector<pair<long long, long long> > v;
    set<long long> s;
    for (j = 0; j < m; j++)
      v.push_back(make_pair(a[i][j], j)), s.insert(a[i][j]);
    vector<long long> pos(s.begin(), s.end());
    sort(v.begin(), v.end());
    long long c = 0;
    for (j = 0; j < m; j++) {
      if (v[j].first > pos[c]) c++;
      xrank[i][v[j].second] = c + 1;
    }
    xdist[i] = (s.size());
  }
  for (j = 0; j < m; j++) {
    vector<pair<long long, long long> > v;
    set<long long> s;
    for (i = 0; i < n; i++)
      v.push_back(make_pair(a[i][j], i)), s.insert(a[i][j]);
    vector<long long> pos(s.begin(), s.end());
    sort(v.begin(), v.end());
    long long c = 0;
    for (i = 0; i < n; i++) {
      if (v[i].first > pos[c]) c++;
      yrank[v[i].second][j] = c + 1;
    }
    ydist[j] = (s.size());
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cout << max(max(xdist[i], xrank[i][j] + ydist[j] - yrank[i][j]),
                  max(ydist[j], yrank[i][j] + xdist[i] - xrank[i][j]))
           << " ";
    }
    cout << '\n';
  }
  return 0;
}
