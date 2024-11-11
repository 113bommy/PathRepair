#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, sum1 = 0, sum2 = 0;
  cin >> n;
  vector<long long> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    sum1 += v[i];
  }
  auto it = max_element(v.begin(), v.end());
  for (int i = *it; i < 101; i++) {
    sum2 = 0;
    for (int j = 0; j < n; j++) sum2 = sum2 + (i - v[j]);
    if (sum2 > sum1) {
      cout << i << "\n";
      break;
    }
  }
  return 0;
}
