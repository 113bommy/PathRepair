#include <bits/stdc++.h>
using namespace std;
long long M = 1e9 + 7;
int main() {
  int n, x;
  long long sum = 0;
  map<int, int> mpp;
  int dis[100005], a[100005], vis[100005];
  set<int> s;
  cin >> n;
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mpp[a[i]]++;
  }
  for (int i = 0; i < n; i++) {
    mpp[a[i]]--;
    if (mpp[a[i]] == 0) mpp.erase(a[i]);
    if (!vis[a[i]]) {
      sum += mpp.size();
      vis[a[i]] = 1;
    }
  }
  cout << sum << endl;
}
