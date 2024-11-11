#include <bits/stdc++.h>
using namespace std;
void dfs(int pos, unsigned long long arr[], int visit[]) {
  if (visit[pos] == 1) {
    cout << pos << " ";
    visit[pos] = 0;
    return;
  }
  visit[pos] = 1;
  dfs(arr[pos], arr, visit);
  visit[pos] = 0;
}
int main() {
  int n, m;
  cin >> n >> m;
  unsigned long long arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  unsigned long long ans = 0;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    ans += min(arr[a], arr[b]);
  }
  cout << ans << "\n";
}
