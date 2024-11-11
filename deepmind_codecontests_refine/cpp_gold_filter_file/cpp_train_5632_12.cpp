#include <bits/stdc++.h>
using namespace std;
int num[101];
int main() {
  int n, m;
  cin >> n >> m;
  int a;
  for (int i = 1; i <= m; i++) {
    cin >> a;
    num[a]++;
  }
  int ans = 0;
  for (int i = 1; i <= 100; i++) {
    int k = 0;
    for (int j = 1; j <= 100; j++) {
      k += num[j] / i;
    }
    if (k >= n)
      ans = i;
    else
      break;
  }
  cout << ans << endl;
  return 0;
}
