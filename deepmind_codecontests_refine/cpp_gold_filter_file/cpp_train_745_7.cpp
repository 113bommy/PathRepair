#include <bits/stdc++.h>
using namespace std;
long long fakt(long long n) {
  long long ret = 1;
  for (int i = 2; i <= n; i++) ret *= i;
  return ret;
}
vector<long long> a;
bool lucky(int n) {
  while (n) {
    if (n % 10 != 4 && n % 10 != 7) return false;
    n /= 10;
  }
  return true;
}
int main() {
  long long n, k;
  scanf("%I64d%I64d", &n, &k);
  if (n <= 15 && fakt(n) < k) {
    printf("-1\n");
    return 0;
  }
  a.push_back(4);
  a.push_back(7);
  int i = 0;
  while (a[i] < n) {
    a.push_back(a[i] * 10 + 4);
    a.push_back(a[i] * 10 + 7);
    i++;
  }
  int sol = 0;
  i = 0;
  while (a[i] <= n - 15) {
    sol++;
    i++;
  }
  vector<long long> pos;
  while (a[i] <= n) {
    pos.push_back(a[i]);
    i++;
  }
  vector<long long> p;
  int mm = 0;
  if (n - 14 > 0) mm = n - 14;
  for (long long i = mm + 1; i <= n; i++) p.push_back(i);
  bool mark[20];
  memset(mark, false, sizeof(mark));
  for (int i = mm + 1; i <= n; i++) {
    long long ff = fakt(n - i);
    long long d = (k - 1) / ff;
    k %= ff;
    if (lucky(i) && lucky(p[d])) sol++;
    mark[p[d] - n + 14] = true;
    p.clear();
    for (int l = mm + 1; l <= n; l++) {
      if (!mark[l - n + 14]) p.push_back(l);
    }
    if (k == 0) {
      i++;
      for (int l = p.size() - 1; l >= 0; l--) {
        if (lucky(i) && lucky(p[l])) sol++;
        i++;
      }
      printf("%d\n", sol);
      return 0;
    }
  }
  printf("%d\n", sol);
  return 0;
}
