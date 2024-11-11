#include <bits/stdc++.h>
using namespace std;
vector<long long> m;
vector<long long> m2;
long long gsd(long long a, long long b) {
  long long t;
  while (b != 0) {
    t = b;
    b = a % b;
    a = t;
  }
  return a;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, i, j, a;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a;
    m.push_back(a);
  }
  sort(m.begin(), m.end());
  for (i = 1; i < m.size(); i++) {
    m2.push_back(m[i] - m[i - 1]);
  }
  long long gsdd = m2[0];
  for (i = 1; i < m2.size(); i++) {
    gsdd = gsd(gsdd, m[i]);
  }
  long long res = 0;
  for (i = 0; i < m2.size(); i++) {
    res += m2[i] / gsdd - 1;
  }
  cout << res;
  return 0;
}
