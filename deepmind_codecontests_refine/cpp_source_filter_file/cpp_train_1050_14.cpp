#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e6 + 7;
const int inf = (int)1e9 + 7;
pair<int, int> ar[N];
int used[N], mt[N];
vector<int> gr[N];
int t;
bool kuhn(int v) {
  if (used[v] == t) return 0;
  used[v] = t;
  for (int to : gr[v]) {
    if (mt[to] == -1) {
      mt[to] = v;
      return 1;
    }
  }
  for (int to : gr[v]) {
    if (kuhn(mt[to])) {
      mt[to] = v;
      return 1;
    }
  }
  return 0;
}
int main() {
  int n;
  scanf("%d", &n);
  vector<int> vec;
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &ar[i].first, &ar[i].second);
    vec.push_back(ar[i].first);
    vec.push_back(ar[i].second);
  }
  sort(vec.begin(), vec.end());
  vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
  for (int i = 1; i <= n; i++) {
    ar[i].first =
        lower_bound(vec.begin(), vec.end(), ar[i].first) - vec.begin();
    ar[i].second =
        lower_bound(vec.begin(), vec.end(), ar[i].second) - vec.begin();
  }
  int m = (int)vec.size();
  for (int i = 1; i <= n; i++) {
    gr[ar[i].first].push_back(m + i - 1);
    gr[ar[i].second].push_back(m + i - 1);
  }
  memset(mt, -1, sizeof mt);
  int cnt = 0;
  t = 1;
  for (int i = 0; i < m; i++) {
    if (kuhn(i)) {
      t++;
      cnt++;
      if (cnt == n) {
        cout << vec[i];
        return 0;
      }
    }
  }
  cout << -1;
}
