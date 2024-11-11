#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<int, int> arr[200001];
int deg[200001];
int par[200001];
int find(int v) {
  if (par[v] == v) return v;
  return par[v] = find(par[v]);
}
int main() {
  cin >> n >> m;
  int mx = 1;
  for (int i = 0; i < n; i++) {
    deg[i] = 0;
    par[i] = i;
  }
  for (int i = 0; i < m; i++) {
    cin >> arr[i].first >> arr[i].second;
    deg[arr[i].first]++;
    deg[arr[i].second]++;
    if (deg[arr[i].first] > deg[mx]) mx = arr[i].first;
    if (deg[arr[i].second] > deg[mx]) mx = arr[i].second;
  }
  int p1, p2;
  for (int i = 0; i < m; i++) {
    if (arr[i].first == mx)
      par[arr[i].second] = arr[i].first;
    else if (arr[i].second == mx)
      par[arr[i].first] = arr[i].second;
    else
      continue;
    cout << arr[i].first << " " << arr[i].second << "\n";
  }
  for (int i = 0; i < m; i++) {
    if (arr[i].first == mx || arr[i].second == mx) continue;
    p1 = find(arr[i].first);
    p2 = find(arr[i].second);
    if (p1 != p2) {
      cout << arr[i].first << " " << arr[i].second << "\n";
      par[p2] = p1;
    }
  }
}
