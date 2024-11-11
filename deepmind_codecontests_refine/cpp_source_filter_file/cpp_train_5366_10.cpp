#include <bits/stdc++.h>
using namespace std;
int main() {
  map<pair<int, int>, long long> m;
  long long n, r = 0;
  cin >> n;
  vector<pair<int, int> > v(n);
  for (int i = 0; i < n; i++) scanf("%d %d", &v[i].first, &v[i].second);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int dx = v[i].first + v[j].first;
      int dy = v[i].second + v[j].second;
      pair<int, int> p = make_pair(dx, dy);
      r += m[p]++;
    }
  }
  printf("%d\n", r / 2);
  return 0;
}
