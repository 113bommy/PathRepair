#include <bits/stdc++.h>
using namespace std;
vector<int> v[1010];
int arr[1010];
int n, ans;
void dfs(int pos) {
  arr[pos]++;
  if (arr[pos] == 2) {
    ans = pos;
    cout << ans << " ";
    return;
  }
  dfs(v[pos][0]);
}
int main() {
  ios_base::sync_with_stdio();
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int q;
    cin >> q;
    v[i].push_back(q);
  }
  for (int i = 1; i <= n; i++) {
    dfs(i);
    for (int i = 0; i < 1000; i++) {
      arr[i] = 0;
    }
  }
}
