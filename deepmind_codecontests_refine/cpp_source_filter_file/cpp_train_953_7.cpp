#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
int n, m, i, j, x, ans;
string st;
vector<pair<int, int> > v, v2;
int f(int x) {
  int s = 1;
  x = min(x, 50);
  while (x--) {
    s = min(inf, s * 2);
  }
  return s;
}
int main() {
  scanf("%d%d", &n, &m);
  m = f(m);
  for ((i) = 1; (i) <= (n); (i)++) {
    int x;
    scanf("%d", &x);
    v.push_back(make_pair(x, 1));
  }
  sort(v.begin(), v.end());
  for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++) {
    if (v2.empty() || v2.back().first != it->first) {
      v2.push_back(*it);
    } else {
      v2.back().second++;
    }
  }
  int s = 0;
  v = v2;
  j = 0;
  int sum = 0;
  for ((i) = 0; (i) < (v.size()); (i)++) {
    while (j < v.size() && j < i + m) {
      sum += v[j++].second;
    }
    ans = max(ans, sum);
    sum -= v[i].second;
  }
  cout << n - ans << endl;
  return 0;
}
