#include <bits/stdc++.h>
int cmp(const void* p, const void* q);
using namespace std;
typedef struct pp {
  long long x;
  long long y;
} ss;
ss aa[200005 * 4];
long long bb[200005 * 4];
ss ak[200005 * 4];
ss bk[200005 * 4];
long long cc[4 * 200005];
long long yy[200005 * 4];
long long vv[200005 * 4];
int main(void) {
  long long i, j, k, p, q;
  scanf("%I64d", &k);
  {
    long long cnt = 0;
    long long x, y;
    memset(vv, 0, sizeof(vv));
    map<pair<int, int>, long long> my;
    memset(yy, 0, sizeof(yy));
    my.clear();
    for (i = 0; i < k; i++) {
      scanf("%I64d %I64d", &x, &y);
      bb[cnt++] = x;
      bb[cnt++] = y;
    }
    for (i = 0; i < cnt; i++) {
      aa[i].x = bb[i];
      aa[i].y = i;
    }
    qsort(aa, cnt, sizeof(ss), cmp);
    cc[0] = 0;
    long long ans = 0;
    for (i = 1; i < cnt; i++) {
      if (aa[i].x != aa[i - 1].x) ans++;
      cc[aa[i].y] = ans;
    }
    long long uu = 0;
    for (i = 0; i < cnt; i++) {
      if (i % 2 == 0) {
        ak[uu].x = cc[i];
      } else {
        ak[uu].y = cc[i];
        uu++;
      }
    }
    long long rns = 0;
    long long bbq = 1;
    for (i = 0; i < uu; i++) {
      pair<int, int> l;
      l.first = ak[i].x;
      l.second = ak[i].y;
      if (my[l] == 0) {
        my[l] = bbq++;
      }
    }
    for (i = 0; i < uu; i++) {
      pair<int, int> l;
      l.first = ak[i].x;
      l.second = ak[i].y;
      vv[my[l]]++;
    }
    long long an = 0;
    for (i = 1; i < bbq; i++) {
      if (vv[i] >= 2) {
        an += vv[i] * (vv[i] - 1) / 2;
      }
    }
    for (i = 0; i < uu; i++) {
      yy[ak[i].x]++;
    }
    long long sum = 0;
    for (i = 0; i < 500005; i++) {
      if (yy[i] >= 2) {
        sum += yy[i] * (yy[i] - 1) / 2;
      }
    }
    memset(yy, 0, sizeof(yy));
    for (i = 0; i < uu; i++) {
      yy[ak[i].y]++;
    }
    for (i = 0; i < 500005; i++) {
      if (yy[i] >= 2) {
        sum += yy[i] * (yy[i] - 1) / 2;
      }
    }
    printf("%I64d\n", sum - an);
  }
  return 0;
}
int cmp(const void* p, const void* q) {
  ss* nn = (ss*)p;
  ss* mm = (ss*)q;
  return nn->x - mm->x;
}
