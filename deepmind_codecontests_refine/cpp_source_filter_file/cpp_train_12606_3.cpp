#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  long long n, m;
  cin >> n >> m;
  long long sum1 = 0, sum2 = 0;
  vector<long long> v;
  for (int i = 0; i < n; i++) {
    long long a, b;
    cin >> a >> b;
    v.push_back(a - b);
    sum1 += a;
    sum2 += b;
  }
  sort(v.rbegin(), v.rend());
  if (sum1 <= m) {
    cout << 0;
    return 0;
  }
  if (sum2 >= m) {
    cout << -1;
    return 0;
  }
  long long count = 0;
  for (int i = 0; i < v.size(); i++) {
    sum1 -= v[i];
    count++;
    if (sum1 <= m) {
      cout << count;
      return 0;
    }
  }
  return 0;
}
