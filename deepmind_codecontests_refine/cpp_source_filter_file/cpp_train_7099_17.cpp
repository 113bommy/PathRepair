#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int q, n;
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> n;
    int arr[200];
    int res[200];
    memset(res, 0, sizeof(res));
    for (int j = 1; j <= n; j++) {
      cin >> arr[j];
    }
    for (int j = 1; j <= n; j++) {
      int step = arr[j];
      res[j]++;
      while (step != j) {
        step = arr[step];
        res[j]++;
      }
    }
    for (int j = 1; j <= n; j++) {
      cout << res[j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
