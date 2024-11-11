#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, a[N];
vector<int> nd[N];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) scanf("%d", a + i), nd[a[i]].push_back(i);
  long long sum = 0;
  for (int i = 2; i <= m; i++)
    sum += ((a[i] - a[i - 1]) < 0 ? -(a[i] - a[i - 1]) : (a[i] - a[i - 1]));
  long long ans = 1LL << 60;
  for (int i = 1; i <= n; i++) {
    int len = nd[i].size();
    static int t[N];
    int tl = 0;
    long long tmp = 0;
    for (int j = 0; j < len; j++) {
      int first = nd[i][j];
      if (first - 1 > 0 && a[first - 1] != i) t[++tl] = a[first - 1];
      if (first + 1 <= m && a[first + 1] != i) t[++tl] = a[first + 1];
    }
    nth_element(t + 1, t + ((tl + 1) / 2), t + tl + 1);
    for (int j = 1; j <= tl; j++)
      tmp += ((i - t[j]) < 0 ? -(i - t[j]) : (i - t[j]));
    long long t1 = t[(tl + 1) / 2];
    for (int j = 1; j <= tl; j++)
      tmp -= ((t1 - t[j]) < 0 ? -(t1 - t[j]) : (t1 - t[j]));
    ans = min(ans, sum - tmp);
  }
  cout << ans << endl;
  return 0;
}
