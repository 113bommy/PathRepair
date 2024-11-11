#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
template <typename T>
constexpr int infValue =
    std::is_same<T, int>::value ? 2000100007 : 8600000000000000007ll;
template <typename T>
constexpr int maxValue =
    std::is_same<T, int>::value ? 1000000007 : 1000000000000000001ll;
const int INF = infValue<int>;
const long long MOD = 1000000007ll;
const double EPS = 1e-6;
const int MAX = maxValue<int>;
int b, d;
char a[110], c[110];
int la, lc;
int answ;
int jp[110], ja[110];
int bit[110], bdd[110];
int main(void) {
  scanf("%d\n%d", &b, &d);
  scanf("%s\n%s", a, c);
  la = strlen(a), lc = strlen(c);
  for (register int i = 0; i < la; ++i) {
    int k = i, cnt = 0;
    for (register int j = 0; j < lc; ++j) {
      int loop = 0;
      while (a[k++] != c[j] && loop < 2) {
        if (k == la) ++cnt, ++loop, k = 0;
      }
      if (k == la) {
        k = 0;
        if (j < lc - 1) ++cnt, ++loop;
      }
      if (j == lc - 1) {
        k = (k - 1 + la) % la;
      }
      if (loop > 1) {
        cnt = -1;
        break;
      }
    }
    if (cnt != -1) {
      jp[i] = k;
      ja[i] = cnt;
    } else {
      answ = -1;
      break;
    }
  }
  if (answ != -1) {
    int pos = 0, jc = 1, dd = 0;
    while (jc + ja[pos] < b) {
      bdd[pos] = dd;
      bit[pos] = jc;
      jc += ja[pos];
      pos = (jp[pos] + 1);
      if (pos == la) ++jc, pos = 0;
      ++dd;
      if (bdd[pos]) break;
      bdd[pos] = dd;
      bit[pos] = jc;
    }
    if (jc) {
      b / jc* dd;
      int pr = 0;
      if (!(jc + ja[pos] <= b))
        pr = bdd[pos];
      else {
        pr =
            bdd[pos] + ((b - bit[pos] - 1) / (jc - bit[pos])) * (dd - bdd[pos]);
        b = (b - bit[pos] - 1) % (jc - bit[pos]);
        jc = dd = 0;
        while (jc + ja[pos] <= b) {
          jc += ja[pos];
          pos = (jp[pos] + 1);
          if (pos == la) ++jc, pos = 0;
          ++dd;
        }
        pr += dd;
      }
      answ = pr / d;
    }
  } else
    answ = 0;
  printf("%d\n", answ);
  return 0;
}
