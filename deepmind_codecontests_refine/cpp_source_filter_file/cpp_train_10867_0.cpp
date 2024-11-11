#include <bits/stdc++.h>
using namespace std;
const int oo = (int)1e9;
const double eps = 1e-7;
int a[200], dist[200], n, d;
pair<int, int> v[200];
int C(int a, int b) {
  return abs(v[a].first - v[b].first) + abs(v[a].second - v[b].second);
}
bool checkBellmanFord() {
  for (int i = 0; i < n; i++) dist[i] = 1000000;
  dist[0] = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++)
        if (j != k)
          if (dist[j] + C(j, k) * d - a[j] < dist[k])
            dist[k] = dist[j] + C(j, k) * d - a[j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (i != j)
        if (dist[i] + C(i, j) * d - a[i] < dist[j]) return 0;
  return true;
}
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  cin >> n >> d;
  for (int i = 0; i < n - 2; i++) cin >> a[i + 1];
  for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
  if (checkBellmanFord())
    cout << dist[n - 1] << endl;
  else {
  }
}
