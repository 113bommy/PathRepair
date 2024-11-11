#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, t, c, n1 = 0, i, p = 1, s = 0, j;
  cin >> n >> t >> c;
  vector<long long> v(n);
  vector<long long> v1;
  for (i = 0; i < n; i++) cin >> v[i];
  for (i = 0; i < n; i++) {
    if (v[i] > t) {
      v1.push_back(i + 1);
      n1++;
    }
  }
  for (i = 0; i < n1; i++) {
    if (v1[i] - p - c + 1 > 0) s += v1[i] - p - c + 1;
    p = v1[i] + 1;
  }
  if (p <= n && n - p - c + 2 > 0) s += n - p - c + 2;
  cout << s;
  return 0;
}
