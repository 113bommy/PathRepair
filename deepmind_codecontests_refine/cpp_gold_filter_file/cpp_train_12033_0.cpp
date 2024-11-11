#include <bits/stdc++.h>
using namespace std;
long long int n, k;
vector<long long int> v[100005];
vector<long long int> res;
long long int ares[100005];
long long int was[100005];
int dfs(long long int ind, long long int c) {
  if (c > 100005) {
    return -1;
  }
  if (ares[ind]) return 1;
  if (!v[ind].size()) {
    ares[ind] = 1;
    res.push_back(ind);
    return 1;
  }
  for (auto i : v[ind]) {
    int r = dfs(i, c + 1);
    if (r < 0) {
      return -1;
    }
  }
  ares[ind] = 1;
  res.push_back(ind);
  return 1;
}
int main() {
  cin >> n >> k;
  long long int *arr = new long long int[k];
  for (long long int i = 0; i < k; i++) {
    cin >> arr[i];
    arr[i]--;
  }
  for (long long int i = 0; i < n; i++) {
    ares[i] = 0;
    long long int a, b;
    cin >> b;
    for (long long int j = 0; j < b; j++) {
      cin >> a;
      a--;
      v[i].push_back(a);
    }
  }
  for (long long int i = 0; i < k; i++) {
    int r = dfs(arr[i], 0);
    if (r < 0) {
      cout << -1;
      return 0;
    }
  }
  cout << res.size() << endl;
  for (auto i : res) {
    cout << (i + 1) << " ";
  }
  return 0;
}
