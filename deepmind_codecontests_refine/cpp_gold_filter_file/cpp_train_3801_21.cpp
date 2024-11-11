#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long> > v;
int main() {
  long long int m = 0, n, i, t = 0, x, ans, val, temp, z = 1e18 + 5, c = 0;
  cin >> x;
  if (x == 1) {
    printf("1\n");
    printf("1 1\n");
    return 0;
  }
  int mx = 10000000;
  while (m < z && mx--) {
    m++;
    if (m == z) break;
    ans = x * 6;
    val = m * (m + 1);
    if (ans % val == 0) {
      temp = (ans / val) + m - 1;
      if (temp % 3 == 0) {
        n = temp / 3;
        z = min(n, z);
        c++;
        if (m == n) t = -1;
        if (m <= n) v.push_back(make_pair(m, n));
      }
    }
  }
  cout << t + v.size() * 2 << endl;
  for (i = 0; i < v.size(); i++) {
    printf("%I64d %I64d\n", v[i].first, v[i].second);
  }
  for (i = v.size() - 1; i >= 0; i--) {
    if (v[i].first == v[i].second) continue;
    printf("%I64d %I64d\n", v[i].second, v[i].first);
  }
}
