#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (long long int i = 1; i < n + 1; i++) cin >> v[i];
    if (v[1] != 0) {
      cout << n + 1 << " ";
      for (long long int i = 1; i < n + 1; i++) cout << i << " ";
      cout << '\n';
      continue;
    }
    if (v[n] == 0) {
      for (long long int i = 1; i < n + 2; i++) cout << i << " ";
      cout << '\n';
      continue;
    }
    int id1 = -1, id2 = -1;
    for (long long int i = 1; i < n; i++) {
      if (v[i + 1] != 0 && v[i] == 0) {
        id1 = i;
        id2 = i + 1;
        break;
      }
    }
    if (id1 == -1) {
      cout << -1 << '\n';
      continue;
    }
    for (long long int i = 1; i < id1 + 1; i++) cout << i << " ";
    cout << n + 1 << " ";
    for (long long int i = id2; i < n + 1; i++) cout << i << " ";
    cout << '\n';
  }
  return 0;
}
