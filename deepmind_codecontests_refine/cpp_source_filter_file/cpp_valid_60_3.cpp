#include <bits/stdc++.h>
using namespace std;
int n;
int a[101];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int test;
  cin >> test;
  while (test--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int res = a[1];
    for (int i = 2; i <= n; i++) res &= a[2];
    cout << res << '\n';
  }
  return 0;
}
