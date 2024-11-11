#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
void solve() {
  long long int n, cnt = 0;
  cin >> n;
  long long int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 2; i < n; i++) {
    if (a[i] > max(a[i + 1], a[i - 1]))
      cnt++;
    else if (a[i] < min(a[i + 1], a[i - 1]))
      cnt++;
  }
  cout << cnt << endl;
}
int main() {
  fast();
  int test = 1;
  while (test--) {
    solve();
  }
  return 0;
}
