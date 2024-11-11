#include <bits/stdc++.h>
using namespace std;
int a[100][100];
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    a[1][i] = 1;
    a[i][1] = 1;
  }
  int mx = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 2; j <= n; j++) {
      a[i][j] = a[i - 1][j] + a[i][j - 1];
      mx = max(a[i][j], mx);
    }
  }
  cout << mx;
}
