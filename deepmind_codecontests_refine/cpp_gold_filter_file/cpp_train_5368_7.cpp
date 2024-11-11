#include <bits/stdc++.h>
int main(int argc, const char *argv[]) {
  long n, m, k;
  scanf("%ld %ld %ld", &n, &m, &k);
  long long roads[100001][3];
  for (long i = 0; i < m; i++) {
    long long u, v, l;
    scanf("%lld %lld %lld", &u, &v, &l);
    roads[i][0] = u;
    roads[i][1] = v;
    roads[i][2] = l;
  }
  long storages[100001];
  for (long i = 0; i < k; i++) {
    long a;
    scanf("%ld", &a);
    storages[i] = a;
  }
  int ind_storages[100001];
  for (long i = 0; i < 100001; i++) {
    ind_storages[i] = 0;
  }
  for (long i = 0; i < k; i++) {
    ind_storages[storages[i]] = 1;
  }
  long long dist = -1;
  for (long i = 0; i < m; i++) {
    if (ind_storages[roads[i][0]] != ind_storages[roads[i][1]]) {
      if (dist == -1 || roads[i][2] < dist) {
        dist = roads[i][2];
      }
    }
  }
  printf("%lld", dist);
  return 0;
}
