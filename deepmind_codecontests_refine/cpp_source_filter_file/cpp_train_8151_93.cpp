#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> v;
  int n, k, l, c, d, p, nl, np, s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  s1 = (l * k) / n;
  s2 = s1 / nl;
  s3 = p / n;
  s4 = (c * d) / n;
  v.push_back(s2);
  v.push_back(s3);
  v.push_back(s4);
  sort(v.begin(), v.end());
  cout << v[0] << endl;
}
