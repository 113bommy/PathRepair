#include <bits/stdc++.h>
using namespace std;
int n, a[101];
void solve() {
  cin >> n;
  n *= 2;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int cnt = 0;
  for (int i = 0; i < n; i += 2) {
    if (a[i] != a[i + 1]) {
      for (int j = i + 1; j < n; j++) {
        if (a[i] == a[j]) {
          for (int k = j - 1; k >= i + 1; k--) {
            cnt++;
            swap(a[k], a[j]);
            j--;
          }
          break;
        }
      }
    }
  }
  cout << cnt;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
