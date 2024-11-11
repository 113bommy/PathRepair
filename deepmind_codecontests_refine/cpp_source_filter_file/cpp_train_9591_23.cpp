#include <bits/stdc++.h>
using namespace std;
const long long int MAX = 1e9 + 10;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k, sum = 0, cur_sum, max_sum = 0;
  cin >> n >> k;
  vector<int> v(n);
  for (int i = 0; i != n; ++i) cin >> v[i], sum += v[i];
  for (int i = 0; i != k; ++i) {
    cur_sum = sum;
    for (int j = 0; j <= n; j += k) {
      cur_sum += v[j];
    }
    max_sum = max(max_sum, abs(cur_sum));
  }
  cout << max_sum;
  return 0;
}
