#include <bits/stdc++.h>
using namespace std;
int ans[1025];
int main() {
  ios::sync_with_stdio(false);
  fill(ans, ans + 100, (int)1e5 + 5);
  int n;
  cin >> n;
  int i = 0;
  for (int i = 0; (1 << i) < n; i++) {
    vector<int> A;
    for (int j = 0; j < n; j++)
      if ((j >> i) % 2 == 1) A.push_back(j + 1);
    cout << A.size() << endl;
    for (int v : A) cout << v << ' ';
    cout << endl;
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;
      if ((j >> i) % 2 == 0) ans[j] = min(ans[j], x);
    }
    vector<int> B;
    for (int j = 0; j < n; j++)
      if ((j >> i) % 2 == 0) B.push_back(j + 1);
    cout << B.size() << endl;
    for (int v : B) cout << v << ' ';
    cout << endl;
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;
      if ((j >> i) % 2 == 1) ans[j] = min(ans[j], x);
    }
  }
  cout << -1 << endl;
  for (int i = 0; i < n; i++) cout << ans[i] << ' ';
  cout << endl;
  return 0;
}
