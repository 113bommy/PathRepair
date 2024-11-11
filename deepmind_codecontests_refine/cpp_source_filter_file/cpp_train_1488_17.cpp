#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int a[N], b[N], last[N], ans[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
      cin >> a[i], b[a[i]] = max(b[a[i]], i - last[a[i]]), last[a[i]] = i;
    for (int i = 1; i <= n; i++) b[a[i]] = max(b[a[i]], n - last[a[i]] + 1);
    for (int i = 1; i <= n; i++) ans[i] = -1;
    int n1 = n;
    for (int i = 1; i <= n; i++) {
      if (b[i] == 0) continue;
      for (int j = b[i]; j <= n1; j++) ans[j] = i;
      n1 = b[i] - 1;
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";
    for (int i = 1; i <= n; i++) b[a[i]] = 0, last[a[i]] = 0;
  }
}
