#include <bits/stdc++.h>
using namespace std;
long long n, m;
vector<vector<long long> > data;
vector<long long> euler, where, depth, logs;
long long table[900000][22];
void dfs(long long vertex, long long d) {
  where[vertex] = euler.size();
  euler.push_back(vertex);
  depth[vertex] = d;
  for (long long i = 0; i < (long long)data[vertex].size(); i++) {
    long long to = data[vertex][i];
    dfs(to, d + 1);
    euler.push_back(vertex);
  }
}
long long Get(long long f, long long s) {
  long long first = where[f];
  long long second = where[s];
  if (first > second) swap(first, second);
  long long dist = second - first + 1;
  long long first_cand = table[first][logs[dist]];
  long long second_cand = table[second + 1 - (1 << logs[dist])][logs[dist]];
  long long ans;
  if (depth[first_cand] < depth[second_cand])
    ans = first_cand;
  else
    ans = second_cand;
  return abs(depth[f] - depth[ans]) + abs(depth[s] - depth[ans]);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (long long i = 0; i < n + 1; i++) {
    vector<long long> help;
    data.push_back(help);
    where.push_back(-1);
    depth.push_back(-1);
  }
  long long x;
  for (long long i = 0; i < n; i++) {
    cin >> x;
    data[x - 1].push_back(i + 1);
  }
  dfs(0, 0);
  long long sz = euler.size();
  for (long long i = 0; i < sz; i++) {
    table[i][0] = euler[i];
  }
  long long counter = 1;
  long long start_log = 1;
  logs.push_back(0);
  for (long long i = 2; i <= 2e6; i *= 2) {
    for (long long j = 0; j + i <= sz; j++) {
      long long fv = table[j][counter - 1];
      long long sv = table[j + i / 2][counter - 1];
      if (depth[fv] <= depth[sv])
        table[j][counter] = fv;
      else
        table[j][counter] = sv;
    }
    for (long long j = start_log; j <= i; j++) {
      logs.push_back(counter - 1);
    }
    start_log = i + 1;
    counter += 1;
  }
  long long d1[n + 1], d2[n + 1], ds[n + 1];
  d1[0] = 0;
  d2[0] = 0;
  ds[0] = 0;
  long long diameter = 0;
  for (long long i = 1; i <= n; i++) {
    long long new_vertex = i;
    long long dia1 = Get(new_vertex, d1[i - 1]);
    long long dia2 = Get(new_vertex, d2[i - 1]);
    if (diameter >= dia1 && diameter >= dia2) {
      d1[i] = d1[i - 1];
      d2[i] = d2[i - 1];
    } else if (dia1 >= dia2) {
      d1[i] = d1[i - 1];
      d2[i] = new_vertex;
      diameter = dia1;
    } else {
      d1[i] = new_vertex;
      d2[i] = d2[i - 1];
      diameter = dia2;
    }
    ds[i] = diameter;
  }
  vector<pair<long long, long long> > events;
  for (long long i = 0; i <= n; i++) {
    long long left = max((long long)0, i - 1);
    long long right = n + 1;
    while (right - left > 1) {
      long long mid = (left + right) / 2;
      long long ds1 = Get(i, d1[mid]);
      long long ds2 = Get(i, d2[mid]);
      if (max(ds1, ds2) == ds[mid])
        left = mid;
      else
        right = mid;
    }
    events.push_back(make_pair(i, 0));
    events.push_back(make_pair(right, 1));
  }
  sort(events.begin(), events.end());
  long long u = 1;
  long long op = 0;
  long long event = 0;
  while (u <= n) {
    while (event < events.size() && events[event].first <= u) {
      if (events[event].second == 1)
        op--;
      else
        op++;
      event++;
    }
    cout << op << endl;
    u++;
  }
  return 0;
}
