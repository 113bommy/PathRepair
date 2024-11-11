#include <bits/stdc++.h>
using namespace std;
long m, j, i, n, k, l, d, p, nl, np, k1, k2, k3, Max, Min = 10000000, ans = 0,
                                                      z, pl = 0, mi = 0;
vector<long> a(110000, 0);
vector<long> b(110000, 0);
set<long> killer;
vector<long> said;
char c;
inline long get() {
  long f;
  scanf("%ld ", &f);
  return f;
}
inline void out(long f) {
  printf("%ld ", f);
  return;
}
int main() {
  n = get();
  m = get();
  said.push_back(0);
  for (i = 1; i <= n; i++) {
    scanf("%c%ld\n", &c, &k);
    if (c == '-') {
      b[k]++;
      mi++;
    } else {
      a[k]++;
      pl++;
    }
    if (c == '-')
      said.push_back(-k);
    else
      said.push_back(k);
  }
  for (i = 1; i <= n; i++) {
    if (a[i] + (mi - b[i]) == m) {
      killer.insert(i);
    }
  }
  for (i = 1; i <= n; i++) {
    if (said[i] > 0 && killer.size() == 1 && *(killer.begin()) == said[i]) {
      printf("Truth\n");
    } else if (said[i] < 0 && killer.count(abs(said[i])) == 0) {
      printf("Truth\n");
    } else if (said[i] > 0 && killer.count(said[i]) == 0) {
      printf("Lie\n");
    } else if (said[i] < 0 && killer.size() == 1 &&
               *(killer.begin()) == abs(said[i])) {
      printf("Lie\n");
    } else
      printf("Not defined\n");
  }
  return 0;
}
