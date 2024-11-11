#include <bits/stdc++.h>
using namespace std;
int arr[100005];
int cnt = 0;
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= 2 * n; i++) {
    cin >> arr[i];
  }
  for (int i = 1; i <= 2 * n; i += 2) {
    for (int j = i + 1; j <= 2 * n; j++) {
      if (arr[j] == arr[i]) {
        for (int k = j; k > i + 1; k--) {
          arr[k] = arr[k - 1];
          cnt++;
        }
        arr[i + 1] = arr[i];
        break;
      }
    }
  }
  cout << cnt << endl;
}
int main() {
  solve();
  return 0;
}
