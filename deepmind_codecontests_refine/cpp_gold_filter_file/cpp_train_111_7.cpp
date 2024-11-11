#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, tmp;
  cin >> n;
  vector<int> v(n);
  int sum = 0, maxi = -1;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    sum += tmp;
    if (tmp > maxi) {
      maxi = tmp;
    }
    v.at(i) = tmp;
  }
  int ans = 0;
  for (int i = maxi; i <= 2 * maxi + 2; i++) {
    int sum_tmp = 0;
    for (int j = 0; j < n; j++) {
      sum_tmp += (i - v.at(j));
    }
    if (sum_tmp > sum) {
      ans = i;
      break;
    }
  }
  cout << ans << '\n';
  return 0;
}
