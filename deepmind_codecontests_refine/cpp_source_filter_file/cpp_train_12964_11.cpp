#include <bits/stdc++.h>
using namespace std;
const int N = 150150;
const int inf = 0x3f3f3f3f;
vector<int> v;
int a[N];
inline bool check(int i) {
  if (i & 1) return a[i] < a[i - 1] && a[i] < a[i + 1];
  return a[i] > a[i - 1] && a[i] > a[i + 1];
}
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  a[0] = inf;
  a[n + 1] = (n & 1) ? inf : 0;
  for (int i = 1; i <= n; ++i)
    if (!check(i)) v.push_back(i);
  if (v.size() > 4)
    puts("0");
  else {
    int ans = 0;
    for (int i = 0; i < v.size(); ++i) {
      for (int j = 1; j <= n; ++j) {
        if (!check(j) && v[i] > j) continue;
        swap(a[v[i]], a[j]);
        bool flag = check(j);
        for (int k = 0; k < v.size(); ++k)
          if (!check(v[k])) flag = 0;
        if (flag) ++ans;
        swap(a[v[i]], a[j]);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
