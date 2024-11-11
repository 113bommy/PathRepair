#include <bits/stdc++.h>
using namespace std;
clock_t start;
void Time(bool timeIt) {
  if (!timeIt) return;
  clock_t end = clock();
  double elapsed_time = ((double)end - (double)start) / (double)CLOCKS_PER_SEC;
  fprintf(stderr, "Time elapsed = %0.4lf\n", elapsed_time);
}
int a[100010], l[100010], r[100010], b[100010];
int main() {
  start = clock();
  int n;
  map<int, int> pos;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    b[i] = a[i];
    pos[a[i]] = i;
    l[i] = i + 1;
    r[i] = i - 1;
  }
  if (n == 1) {
    printf("%d\n", a[1] + 1);
    return 0;
  }
  r[0] = -1;
  l[0] = 1;
  r[n + 1] = n;
  l[n + 1] = n + 2;
  sort(b + 1, b + n + 1);
  map<int, int> mp;
  int num = 0, k = 0;
  for (int i = 1; i <= n; ++i) {
    if (mp.size() == 1) {
      if (mp.begin()->second > num) {
        k = b[i];
        num = mp.begin()->second;
      }
    }
    int m = b[i], p = pos[m];
    r[p] = r[p + 1];
    l[p] = l[p - 1];
    if (r[p + 1] > p) {
      mp[r[p + 1] - p]--;
      if (mp[r[p + 1] - p] == 0) mp.erase(r[p + 1] - p);
    }
    if (l[p - 1] < p) {
      mp[p - l[p - 1]]--;
      if (mp[p - l[p - 1]] == 0) mp.erase(p - l[p - 1]);
    }
    mp[r[p] - l[p] + 1]++;
  }
  printf("%d\n", k);
  Time(true);
  return 0;
}
