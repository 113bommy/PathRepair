#include <bits/stdc++.h>
using namespace std;
long long cnt[512], negcnt[512];
long long op[100010], a[100010];
void printinblock(long long idx, long long remov) {
  stack<long long> s1;
  long long end1 = ((idx + 1) * 400);
  for (long long i = (idx * 400); i < end1; ++i) {
    if (op[i] == 1) {
      s1.push(a[i]);
    } else if (op[i] == -1 && s1.size()) {
      s1.pop();
    }
  }
  while (remov--) {
    assert(s1.size());
    s1.pop();
  }
  printf("%lld\n", s1.top());
}
void print() {
  long long temp = 0;
  for (long long i = 400 - 1; i >= 0; --i) {
    if ((cnt[i] - temp) > 0) {
      printinblock(i, temp);
      return;
    }
    temp += negcnt[i];
    temp -= cnt[i];
  }
  printf("-1\n");
}
signed main() {
  long long m;
  scanf("%lld", &m);
  while (m--) {
    long long p, t, x;
    scanf("%lld", &p);
    scanf("%lld", &t);
    if (t == 1) {
      scanf("%lld", &x);
      a[p] = x;
      op[p] = 1;
      long long blkid = (p / 400);
      long long end1 = ((blkid + 1) * 400);
      long long temp = 0;
      negcnt[blkid] = 0;
      for (long long i = (blkid * 400); i < end1; ++i) {
        temp += op[i];
        if (temp < 0) ++negcnt[blkid];
        temp = max(temp, 0LL);
      }
      cnt[blkid] = temp;
      print();
    } else {
      op[p] = -1;
      long long blkid = (p / 400);
      long long end1 = ((blkid + 1) * 400);
      long long temp = 0;
      negcnt[blkid] = 0;
      for (long long i = (blkid * 400); i < end1; ++i) {
        temp += op[i];
        if (temp < 0) ++negcnt[blkid];
        temp = max(temp, 0LL);
      }
      cnt[blkid] = temp;
      print();
    }
  }
  return 0;
}
