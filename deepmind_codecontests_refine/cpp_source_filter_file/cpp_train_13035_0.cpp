#include <bits/stdc++.h>
using namespace std;
int n, s, k;
int a[10010];
bool ima(int t) {
  for (int i = 0; i < k; i++)
    if (a[i] == t) return false;
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> s >> k;
    for (int i = 0; i < k; i++) cin >> a[i];
    int sol = 1e9;
    for (int i = s; i < n; i++)
      if (ima(i)) {
        sol = i - s;
        break;
      }
    for (int i = s; i > 0; i--)
      if (ima(i)) {
        sol = min(sol, s - i);
        break;
      }
    cout << sol << endl;
  }
  return 0;
}
