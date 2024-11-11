#include <bits/stdc++.h>
using namespace std;
int visited[1000105];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    visited[a]++;
  }
  int ans = 0;
  for (int i = 0; i <= 1000100; i++) {
    while (visited[i] > 1) {
      int l = log2(visited[i]);
      int val = (i + l);
      visited[val]++;
      visited[i] -= (1 << l);
    }
    ans += visited[i];
  }
  cout << ans << endl;
}
