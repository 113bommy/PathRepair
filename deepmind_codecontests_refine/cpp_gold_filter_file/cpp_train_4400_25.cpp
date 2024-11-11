#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int friends[n], ans[n];
  for (int i = 0; i < n; i++) {
    cin >> friends[i];
    ans[i] = 1;
  }
  for (int i = 1; i < n + 1; i++) {
    for (int j = 0; j < n; j++) {
      if (friends[j] == i) {
        j = n;
      } else {
        ans[i - 1]++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
}
