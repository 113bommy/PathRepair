#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, x, ans = 0, arr[102] = {0};
  cin >> n;
  while (n--) {
    cin >> x;
    arr[x]++;
  }
  while (1) {
    bool flag = 0;
    for (int i = 0; i < 101; i++) {
      for (int j = 0; j < 101; j++) {
        if (i != j && arr[i] >= 2 && arr[j] >= 2) {
          ans++, arr[i] -= 2, arr[j] -= 2;
          flag = 1;
        }
      }
    }
    if (!flag) {
      break;
    }
  }
  for (int i = 0; i < 100; i++) {
    if (arr[i] >= 4) {
      ans += arr[i] / 4;
    }
  }
  cout << ans;
}
