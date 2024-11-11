#include <bits/stdc++.h>
using namespace std;
bool arr[1010], arr1[1010];
int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  int ans = 1e9 + 50;
  for (int i = 0; i < m - n + 1; i++) {
    int sum = 0;
    int p = i + n, x = 0;
    for (int y = i; y < p; y++, x++) {
      if (s[x] != t[y]) {
        sum++;
        arr[y] = 1;
      }
    }
    if (ans > sum) {
      ans = sum;
      for (int o = 0; o < 1010; o++) {
        arr1[o] = arr[o];
        arr[o] = 0;
      }
    } else {
      for (int o = 0; o < 1010; o++) arr[o] = 0;
    }
  }
  cout << ans << endl;
  for (int i = 0; i < m; i++) {
    if (arr1[i]) cout << i + 1 << " ";
  }
  cout << endl;
  return 0;
}
