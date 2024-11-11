#include <bits/stdc++.h>
using namespace std;
map<string, int> d;
int arr[100000], cost[100000], group[100000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m, k;
  cin >> n >> k >> m;
  string s;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    d[s] = i;
  }
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    cost[i] = (1 << 30);
  }
  for (int i = 1; i <= k; i++) {
    int x;
    cin >> x;
    while (x--) {
      int a;
      cin >> a;
      group[a] = i;
      cost[i] = min(cost[i], arr[a]);
    }
  }
  long long ans = 0;
  while (m--) {
    string shit;
    cin >> shit;
    ans += cost[group[d[shit]]];
  }
  cout << ans;
  return 0;
}
