#include <bits/stdc++.h>
using namespace std;
int nr[(int)1e5];
bool solve(int n, int h, long long s) {
  memset(nr, 0, sizeof(nr));
  long long cs = 0;
  for (int i = 0; i < n; i++) {
    nr[i]++;
    cs += i + 1;
  }
  if (cs < s) return false;
  for (int i = n - 1, j = 0, mh = 1; i >= 0 && cs > s; i--) {
    while (i > j && nr[j] == mh) {
      j++;
      mh *= h;
    }
    int d = min((long long)i - j, cs - s);
    if (d == 0) return false;
    nr[i - d]++;
    nr[i]--;
    cs -= d;
  }
  return cs == s;
}
void go(int i, int& ret, vector<int>& sol, int h, int p = -1, int l = 0) {
  if (i > 0) sol[i - 1] = p;
  int c = min(h, nr[l + 1]);
  nr[l + 1] -= c;
  for (int j = 0; j < c; j++) {
    ++ret;
    go(ret, ret, sol, h, i, l + 1);
  }
}
int main() {
  int n;
  long long s;
  scanf("%d %I64d", &n, &s);
  int k = 1;
  for (; k <= n; k <<= 1)
    ;
  int h = -1;
  for (; k; k >>= 1) {
    if (h + k < n && !solve(n, h + k, s)) h += k;
  }
  h++;
  if (h == n) {
    printf("No\n");
    return 0;
  }
  solve(n, h, s);
  vector<int> sol(n - 1);
  int nn = 0;
  go(0, nn, sol, h);
  printf("Yes\n");
  for (auto e : sol) printf("%d ", e + 1);
  printf("\n");
  return 0;
}
