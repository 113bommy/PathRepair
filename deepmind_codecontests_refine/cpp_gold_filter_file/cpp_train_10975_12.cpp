#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
char s[N];
int l[N], r[N], p[N];
pair<int, int> v[N];
int main() {
  scanf("%s", s);
  int n = strlen(s);
  p[0] = 0;
  l[0] = N, r[0] = -N;
  for (int i = 1; i <= n; i++) {
    l[i] = min(l[i - 1], p[i - 1]);
    r[i] = max(r[i - 1], p[i - 1]);
    if (s[i - 1] == 'L')
      p[i] = p[i - 1] - 1;
    else
      p[i] = p[i - 1] + 1;
  }
  if (p[n] > r[n] || p[n] < l[n])
    printf("1\n");
  else {
    int ans = 0;
    for (int i = 1; i < n; i++) {
      v[i - 1].first = l[i];
      v[i - 1].second = i;
    }
    sort(v, v + n - 1);
    int j = 0;
    int m = -N;
    for (int i = l[n]; i < 0; i++) {
      while (j < n - 1 && v[j].first <= i) {
        int jj = v[j].second;
        m = max(m, p[jj] - l[jj]);
        j++;
      }
      int x = p[n] - l[n] + i + 1;
      if (x > m + i + 1 && x > r[n]) {
        ans++;
      }
    }
    for (int i = 1; i < n; i++) {
      v[i - 1].first = r[i];
      v[i - 1].second = i;
    }
    sort(v, v + n - 1);
    reverse(v, v + n - 1);
    j = 0;
    m = N;
    for (int i = r[n]; i > 0; i--) {
      while (j < n - 1 && v[j].first >= i) {
        int jj = v[j].second;
        m = min(m, p[jj] - r[jj]);
        j++;
      }
      int x = p[n] - r[n] + i - 1;
      if (x < m + i - 1 && x < l[n]) {
        ans++;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
