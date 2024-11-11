#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, q, m;
  cin >> n >> q >> m;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  vector<tuple<int, int, int> > queries;
  for (int i = 0; i < q; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    queries.push_back(tie(a, b, c));
  }
  vector<int> p(m);
  for (int i = 0; i < m; i++) cin >> p[i];
  for (int i = q - 1; i >= 0; i--) {
    int a, b, c;
    tie(a, b, c) = queries[i];
    if (a == 1) {
      for (int j = 0; j < m; j++) {
        if (b < p[j] && p[j] <= c)
          p[j]--;
        else if (p[j] == b)
          p[j] = c;
      }
    } else {
      for (int j = 0; j < m; j++)
        if (b <= p[j] && p[j] <= c) p[j] = b + (c - p[j]);
    }
  }
  for (auto i : p) cout << v[i - 1] << " ";
  cout << endl;
  return 0;
}
