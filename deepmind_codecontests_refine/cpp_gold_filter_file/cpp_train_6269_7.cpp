#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[101][101] = {0};
  int ar[101] = {0};
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    arr[a][b] = 1;
    arr[b][a] = 1;
    ar[a]++;
    ar[b]++;
  }
  int ans = 0;
  while (true) {
    int ada = 0;
    vector<int> v;
    for (int i = 1; i <= n; i++) {
      if (ar[i] == 1) {
        v.push_back(i);
        ada++;
      }
    }
    if (ada == 0) break;
    for (int i = 0; i < v.size(); i++) {
      ar[v[i]]--;
      for (int j = 1; j <= n; j++) {
        if (arr[v[i]][j] == 1 || arr[j][v[i]] == 1) {
          ar[j]--;
          arr[v[i]][j] = 0;
          arr[j][v[i]] = 0;
        }
      }
    }
    ans++;
  }
  cout << ans << endl;
  return 0;
}
