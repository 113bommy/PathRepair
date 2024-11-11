#include <bits/stdc++.h>
using namespace std;
pair<int, int> v[200005];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &v[i].first, &v[i].second);
  }
  sort(v, v + n);
  int tv1_NotUsable = -1, tv2_NotUsable = -1;
  for (int i = 0; i < n; i++) {
    if (tv1_NotUsable < v[i].first)
      tv1_NotUsable = v[i].second;
    else if (tv2_NotUsable < v[i].first)
      tv2_NotUsable = v[i].second;
    else {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
}
