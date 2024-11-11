#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k, i;
  cin >> n >> k;
  int cnt = 1;
  for (i = 1; i <= (n - k); i++) {
    cout << cnt << " " << cnt + 1 << " ";
    cnt += 2;
  }
  for (i = 1; i <= k; i++) {
    cout << cnt + 1 << " " << cnt << " ";
    cnt += 2;
  }
}
