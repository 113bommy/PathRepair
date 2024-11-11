#include <bits/stdc++.h>
using namespace std;
long long n;
long long prob[2][1000000];
int ind[3];
int curind[3];
struct A {
  long long a, b;
} aa[1000000];
int main() {
  cin >> n;
  int i, j;
  long long k, a1, x, y, m;
  int cnt = 0;
  int xx = 0;
  int sss = 0;
  for (i = 1; i <= n; i++) {
    cin >> k >> a1 >> x >> y >> m;
    ind[i - 1] = 0;
    sss += k;
    prob[i - 1][++ind[i - 1]] = a1;
    for (j = 1; j <= k - 1; j++) {
      ++ind[i - 1];
      prob[i - 1][ind[i - 1]] = prob[i - 1][ind[i - 1] - 1] * x + y;
      prob[i - 1][ind[i - 1]] %= m;
    }
    curind[i - 1] = 1;
  }
  for (i = 1; i <= sss; i++) {
    long long mn = 99999999999LL, indxm = -1;
    long long nxt = 99999999999LL, indn = -1;
    for (j = 0; j <= n - 1; j++) {
      if (curind[j] <= ind[j] && nxt > prob[j][curind[j]] &&
          prob[j][curind[j]] >= aa[i - 1].a) {
        nxt = prob[j][curind[j]];
        indn = j;
      }
      if (curind[j] <= ind[j] && mn > prob[j][curind[j]]) {
        mn = prob[j][curind[j]];
        indxm = j;
      }
    }
    if (indn != -1) {
      aa[++xx].a = nxt;
      aa[xx].b = indn + 1;
      curind[indn]++;
    } else {
      cnt++;
      aa[++xx].a = mn;
      aa[xx].b = indxm + 1;
      curind[indxm]++;
    }
  }
  cout << cnt << endl;
  if (sss <= 200000) {
    for (i = 1; i <= xx; i++) {
      cout << aa[i].a << " " << aa[i].b << endl;
    }
  }
}
