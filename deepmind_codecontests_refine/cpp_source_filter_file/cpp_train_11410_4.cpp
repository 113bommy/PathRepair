#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int n, s, arr[N];
vector<vector<int> > adjList(N);
long long solve(int node, int parent) {
  if (node != s) arr[node]--;
  vector<long long> vec;
  for (int ch : adjList[node]) {
    if (ch != parent) {
      vec.push_back(solve(ch, node));
    }
  }
  sort(vec.begin(), vec.end());
  long long ans = 0;
  while (vec.size() && arr[node]) {
    ans += vec.back() + 2;
    vec.pop_back();
    arr[node]--;
  }
  for (int i = 0; i < adjList[node].size() && arr[node]; i++) {
    int ch = adjList[node][i];
    if (ch != parent) {
      ans += min(arr[node], arr[ch]);
      arr[node] -= min(arr[node], arr[ch]);
    }
  }
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    adjList[x].push_back(y), adjList[y].push_back(x);
  }
  scanf("%d", &s);
  printf("%lld", solve(s, s));
  return 0;
}
