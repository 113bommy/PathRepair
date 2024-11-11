#include <bits/stdc++.h>
using namespace std;
const int N = 1e2;
int n;
int ar[N + 2];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= 2 * n; i++) {
    cin >> ar[i];
  }
  int ans = 0;
  for (int i = 1; i <= 2 * n; i += 2) {
    int pos = 0;
    for (int j = i + 1; j <= 2 * n; j++) {
      if (ar[j] == ar[i]) {
        pos = j;
        break;
      }
    }
    for (int j = pos; j >= i + 2; j--) {
      swap(ar[j], ar[j - 1]);
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}
