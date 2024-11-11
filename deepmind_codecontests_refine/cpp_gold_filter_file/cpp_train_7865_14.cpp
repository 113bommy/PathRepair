#include <bits/stdc++.h>
using namespace std;
int comp[2000001], has[2000001];
set<int> pri;
void pre() {
  for (long long i = 2; i < 2000001; ++i) {
    if (comp[i]) continue;
    for (long long j = i * i; j < 2000001; j += i) {
      comp[j] = 1;
    }
  }
  for (int i = 2; i < 2000001; ++i)
    if (!comp[i]) pri.insert(i);
}
int main() {
  pre();
  int n, x;
  scanf("%d%d", &n, &x);
  if (x == 2) {
    printf("0\n");
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    if (a >= 2000001) continue;
    has[a] = 1;
  }
  if (has[1]) {
    printf("1\n");
    return 0;
  }
  if (x > *pri.rbegin()) {
    printf("-1\n");
    return 0;
  }
  int r = 0, s = 2;
  while (s < x) {
    if (*pri.begin() == s) {
      if (!has[s]) {
        r = -1;
        break;
      }
      ++r;
      pri.erase(pri.begin());
    }
    ++s;
  }
  printf("%d\n", r);
}
