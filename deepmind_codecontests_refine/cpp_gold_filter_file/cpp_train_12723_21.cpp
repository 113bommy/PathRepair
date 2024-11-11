#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int a[N], n;
int main() {
  scanf("%d", &n);
  map<int, int> m;
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]), m[a[i]]++;
  vector<pair<int, int> > v(m.begin(), m.end());
  v[0].second += 1;
  for (int i = v.size() - 1; i > 0; --i) {
    if (v[i].first != v[i - 1].first + 1 || v[i].second >= v[i - 1].second) {
      printf("NO\n");
      return 0;
    }
    v[i - 1].second -= v[i].second;
  }
  if (v[0].second == 1)
    printf("YES\n");
  else
    printf("NO\n");
}
