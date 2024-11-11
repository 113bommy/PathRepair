#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, i, j, c, d, b, x;
  int y = 0;
  cin >> n >> m;
  long long int a;
  vector<int> v;
  map<int, int> k;
  for (i = 0; i < m; i++) {
    x = -1;
    c = 0;
    for (j = 0; j < n; j++) {
      cin >> a;
      if (a > x) {
        c = j + 1;
        x = max(x, a);
      }
    }
    v.push_back(c);
  }
  sort(v.begin(), v.end());
  for (i = 0; i < v.size(); i++) {
    k[v[i]]++;
    if (k[v[i]] > y) {
      y = max(y, k[v[i]]);
      d = v[i];
    }
  }
  cout << d << endl;
  return 0;
}
