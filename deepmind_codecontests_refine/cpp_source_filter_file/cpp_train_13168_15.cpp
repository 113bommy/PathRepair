#include <bits/stdc++.h>
using namespace std;
const int INF = (int)(INT_MAX - 100);
const int N = (int)(1e+5 + 1);
const long long mod = (int)(1e+9 + 7);
int v[2][N];
int main() {
  int n, s;
  cin >> n >> s;
  int p, q;
  char d;
  for (int it1 = 0; it1 < n; it1++) {
    cin >> d >> p >> q;
    v[(d == 'B')][p] += q;
  }
  int k = 0;
  vector<pair<int, int> > v2;
  for (int p = (0); p <= (N); p++) {
    if (v[0][p] > 0) {
      v2.push_back({p, v[0][p]});
      k++;
    }
    if (k == s) break;
  }
  for (int it1 = int(v2.size()) - 1; it1 >= 0; it1--)
    cout << "S " << v2[it1].first << " " << v2[it1].second << '\n';
  k = 0;
  for (int p = (N); p >= (0); p--) {
    if (v[1][p] > 0) {
      cout << "B " << p << " " << v[1][p] << '\n';
      k++;
    }
    if (k == s) break;
  }
  return 0;
}
