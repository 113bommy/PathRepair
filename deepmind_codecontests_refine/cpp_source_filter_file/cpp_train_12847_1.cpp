#include <bits/stdc++.h>
using namespace std;
int n, m;
int d[70005];
int max_d;
int min_d;
pair<int, pair<int, int> > a[70005];
int r[70005];
int p[70005];
void process() {
  d[0] = 1;
  max_d = min_d = 0;
  int i, j;
  int k = m - a[n].second.first;
  int af = a[n].second.first;
  for (i = n - 1; i > 0; i--) {
    int l = max_d;
    if (af != a[i].second.first) {
      min_d = 0;
      af = a[i].second.first;
    }
    for (j = max_d; j >= min_d; j--) {
      if (d[j]) {
        if (j + a[i].second.first <= k) {
          if (d[j + a[i].second.first] == 0) {
            d[j + a[i].second.first] = i;
            if (max_d < j + a[i].second.first) max_d = j + a[i].second.first;
          }
        }
      }
      if (d[k]) break;
    }
    if (d[k]) break;
    min_d = l;
  }
  if (d[k] == 0) {
    printf("-1");
    return;
  }
  i = d[k];
  j = k;
  int cnt = 0;
  while (j > 0) {
    a[i].first = 1;
    j -= a[i].second.first;
    i = d[j];
    cnt++;
  }
  sort(a + 1, a + n + 1);
  cnt = n - cnt - 1;
  if (cnt == 0) {
    for (i = 1; i <= n; i++) {
      r[a[i].second.second] = a[i].second.first;
      p[a[i].second.second] = 0;
    }
  } else {
    for (i = cnt + 1; i < n; i++) {
      r[a[i].second.second] = a[i].second.first;
      p[a[i].second.second] = 0;
    }
    r[a[n].second.second] = a[n].second.first - a[cnt].second.first;
    p[a[n].second.second] = a[cnt].second.second;
    for (i = cnt; i > 1; i--) {
      r[a[i].second.second] = a[i].second.first - a[i - 1].second.first;
      p[a[i].second.second] = a[i - 1].second.second;
    }
    r[a[1].second.second] = a[1].second.first;
    p[a[1].second.second] = 0;
  }
  for (i = 1; i <= n; i++) {
    printf("%d ", r[i]);
    if (p[i])
      printf("1 %d\n", p[i]);
    else
      printf("0\n");
  }
}
int main() {
  int i, j;
  scanf("%d %d", &n, &m);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i].second.first);
    a[i].second.second = i;
  }
  sort(a + 1, a + n + 1);
  a[n].first = 1;
  if (a[n].second.first > m)
    printf("-1\n");
  else {
    process();
  }
}
