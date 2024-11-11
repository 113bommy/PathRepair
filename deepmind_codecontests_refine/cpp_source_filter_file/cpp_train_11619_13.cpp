#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  long long a1, b, c, i, j, k;
  vector<pair<int, int> > v;
  pair<int, int> a;
  for (i = 1; i <= n; i++) {
    cin >> a.first;
    a.second = i;
    v.push_back(a);
  }
  sort(v.begin(), v.end());
  int t[n + 1];
  for (i = 0; i < n; i++) {
    t[v[i].second] = i;
  }
  for (i = 0; i < m; i++) {
    cin >> a1 >> b >> c;
    a1--;
    b--;
    c--;
    k = t[c];
    for (j = a1; j <= b; j++) {
      if (t[j] < k) a1++;
    }
    if (a1 == c)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}
