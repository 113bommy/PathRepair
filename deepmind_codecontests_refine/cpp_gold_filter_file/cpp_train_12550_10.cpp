#include <bits/stdc++.h>
using namespace std;
int main() {
  map<long long, pair<long long, bool>> mp, mp1;
  long long a, m, b, c, n, y, res = 0, res2 = 0;
  vector<long long> v, v1;
  cin >> n >> c;
  for (long long i = 0; i < n; i++) {
    cin >> a;
    v.push_back(a);
  }
  res = 1;
  for (long long i = 0; i < n - 1; i++) {
    if (v[i + 1] - v[i] > c)
      res = 1;
    else
      res++;
  }
  cout << res << endl;
  return 0;
}
