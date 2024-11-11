#include <bits/stdc++.h>
using namespace std;
int n, m;
int num[111];
int check(int x) {
  int sum = 0;
  for (int i = 1; i <= 100; i++) {
    sum += num[i] / x;
  }
  return sum >= n;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int mid;
    cin >> mid;
    num[mid]++;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!check(i)) {
      break;
    }
    ans = i;
  }
  cout << ans << endl;
}
