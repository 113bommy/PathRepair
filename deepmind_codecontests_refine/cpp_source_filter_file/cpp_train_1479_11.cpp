#include <bits/stdc++.h>
using namespace std;
long long findColor(long long c1, long long c2, vector<long long> nodes,
                    long long **a) {
  long long size = nodes.size(), sum = 0;
  vector<long long> colors(size);
  colors[0] = c1;
  sum += a[c1][nodes[0]];
  colors[1] = c2;
  sum += a[c2][nodes[1]];
  for (long long i = 2; i < size; ++i) {
    colors[i] = 3 - (colors[i - 1] + colors[i - 2]);
    sum += a[colors[i]][nodes[i]];
  }
  return sum;
}
int main() {
  long long n, u, v, s;
  bool status = 1;
  long long **c;
  c = new long long *[3];
  cin >> n;
  vector<long long> g[n + 1];
  vector<long long> colors(n + 1);
  vector<long long> nodes;
  for (long long i = 0; i < 3; ++i) c[i] = new long long[n + 1];
  for (long long i = 0; i < 3; ++i)
    for (long long j = 0; j < n; ++j) cin >> c[i][j + 1];
  for (long long i = 0; i < n - 1; ++i)
    cin >> u >> v, g[u].push_back(v), g[v].push_back(u);
  for (long long i = 0; i < n; ++i) {
    if (g[i + 1].size() > 2) status = 0;
    if (g[i + 1].size() == 1) s = (i + 1);
  }
  if (status == 0)
    cout << -1 << "\n";
  else {
    long long prev = s;
    nodes.push_back(s);
    nodes.push_back(g[s][0]);
    prev = g[s][0];
    for (long long i = 0; i < n - 2; ++i) {
      if (g[prev][0] != nodes[nodes.size() - 2])
        prev = (g[prev][0]);
      else
        prev = (g[prev][1]);
      nodes.push_back(prev);
    }
    long long minm = (long long)(1e9), c1, c2, c3;
    long long option[] = {0, 1, 2};
    for (long long i = 0; i < 3; ++i)
      for (long long j = 0; j < 3; ++j) {
        if (i == j) continue;
        long long temp = findColor(option[i], option[j], nodes, c);
        if (temp < minm) minm = temp, c1 = option[i], c2 = option[j];
      }
    cout << minm << "\n";
    colors[nodes[0]] = c1;
    colors[nodes[1]] = c2;
    for (long long i = 2; i < n; ++i)
      c3 = c1, c1 = c2, c2 = (3 - c3 - c1), colors[nodes[i]] = c2;
    for (long long i = 0; i < n; ++i) cout << colors[i + 1] + 1 << " ";
    cout << '\n';
  }
  return 0;
}
