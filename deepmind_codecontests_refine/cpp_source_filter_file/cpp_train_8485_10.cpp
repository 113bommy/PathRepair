#include <bits/stdc++.h>
using namespace std;
int a[505][505];
int main() {
  long long i, j;
  ios_base ::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  int num = n * n;
  for (i = 1; i < n + 1; i++) {
    for (j = n; j >= k; j--) {
      a[i][j] = num;
      num--;
    }
  }
  for (i = 1; i < n + 1; i++) {
    for (j = k - 1; j >= 1; j--) {
      a[i][j] = num;
      num--;
    }
  }
  long long ans = 0;
  for (i = 1; i < n + 1; i++) {
    ans += a[i][k];
  }
  cout << "\n";
  for (i = 1; i < n + 1; i++) {
    for (j = 1; j < n + 1; j++) {
      cout << a[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
