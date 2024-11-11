#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, a[N];
vector<int> nd[N];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", a + i), nd[a[i]].push_back(i);
  long long sum = 0;
  for (int i = 2; i <= n; i++)
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
      if (first + 1 <= n && a[first + 1] != i) t[++tl] = a[first + 1];
    }
    nth_element(t + 1, t + ((tl + 1) / 2), t + tl + 1);
    for (int j = 1; j <= tl; j++)
      tmp += ((i - a[j]) < 0 ? -(i - a[j]) : (i - a[j]));
    long long t1 = t[(tl + 1) / 2];
    for (int j = 1; j <= tl; j++)
      tmp -= ((t1 - a[j]) < 0 ? -(t1 - a[j]) : (t1 - a[j]));
    ans = min(ans, sum - tmp);
  }
  cout << ans << endl;
  return 0;
}
