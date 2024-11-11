#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int v[100005];
  int morte[100005];
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    morte[i] = 1000000009;
  }
  v[0] = 0;
  v[n + 1] = 0;
  morte[0] = 0;
  morte[n + 1] = 0;
  for (int i = 1; i <= n; i++)
    morte[i] = min(morte[i - 1] + 1, min(morte[i], v[i]));
  for (int i = n; i >= 1; i--)
    morte[i] = min(morte[i + 1] + 1, min(morte[i], v[i]));
  int res = 0;
  for (int i = 1; i <= n; i++) res = max(res, morte[i]);
  cout << res << endl;
}
