#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  int cnt = __builtin_ffs(n) - 2;
  for (int i = 0; i < n; i++) cin >> a[i];
  priority_queue<int, vector<int>, greater<int>> q;
  if (a[n - 1] == -1) return puts("0"), 0;
  long long ans = a[n - 1];
  int j = n - 1;
  for (int i = 0; i < (1 << cnt); i++) {
    j--;
    if (a[j] == -1) {
      cout << ans << endl;
      return 0;
    }
    q.push(a[j]);
  }
  while (!q.empty()) {
    ans += q.top();
    q.pop();
    cnt--;
    for (int i = 0; i < (1 << cnt); i++) {
      j--;
      if (a[j] == -1) {
        cout << ans << endl;
        return 0;
      }
      q.push(a[j]);
    }
    if (j == 0) break;
  }
  cout << ans << endl;
}
