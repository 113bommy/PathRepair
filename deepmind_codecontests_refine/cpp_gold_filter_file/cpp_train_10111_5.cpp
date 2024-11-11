#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N], b[N], c[N], used[N];
int main() {
  int n, cnt = 0, flag = 0, cnt1 = 1, ans;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    a[i] = n - a[i];
    c[a[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    if (c[a[i]] % a[i] != 0) {
      cout << "Impossible" << endl;
      return 0;
    }
  }
  cout << "Possible" << endl;
  for (int i = 1; i <= n; i++) {
    if (c[a[i]] % a[i] == 0) {
      cnt++;
      ans = cnt;
      used[a[i]] = cnt;
      c[a[i]]--;
    } else {
      ans = used[a[i]];
      c[a[i]]--;
    }
    cout << ans << ' ';
  }
  return 0;
}
