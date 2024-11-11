#include <bits/stdc++.h>
using namespace std;
vector<long long> rec;
int count(int x) {
  int cnt = 0;
  while (x) {
    cnt += x & 1;
    x >>= 1;
  }
  return cnt;
}
int main() {
  long long l, r, k;
  cin >> l >> r >> k;
  long long len = r - l + 1;
  if (len <= 4) {
    int tot = 1 << len;
    long long res = 1LL << 60;
    for (int i = 1; i < tot; i++) {
      long long tmp = 0;
      for (int j = 0; j < len; j++) {
        if ((i >> j) & 1) {
          tmp ^= l + j;
        }
      }
      if (tmp < res && count(i) <= k) {
        res = tmp;
        rec.clear();
        for (int j = 0; j < len; j++) {
          if ((i >> j) & 1) rec.push_back(l + j);
        }
      }
    }
    cout << res << endl;
    cout << rec.size() << endl;
    cout << rec[0];
    for (int i = 1; i < rec.size(); i++) {
      cout << " " << rec[i];
    }
    cout << endl;
  } else {
    if (k == 1) {
      printf("%I64d\n%d\n%I64d\n", l, 1, l);
      return 0;
    } else if (k == 2) {
      if (l & 1) l++;
      printf("%d\n%d\n%I64d %I64d\n", 1, 2, l, l + 1);
      return 0;
    } else if (k >= 4) {
      if (l & 1) l++;
      printf("%d\n%d\n%I64d %I64d %I64d %I64d\n", 0, 4, l, l + 1, l + 2, l + 3);
      return 0;
    }
    long long x = -1, y, z;
    for (long long i = 3; i <= r; i <<= 1) {
      if ((i ^ (i - 1)) >= l) {
        x = i;
        y = i - 1;
        z = i ^ (i - 1);
        printf("0\n");
        printf("3\n");
        printf("%I64d %I64d %I64d\n", x, y, z);
        break;
      }
    }
    if (x == -1) {
      if (l & 1) l++;
      x = l;
      y = l + 1;
      printf("1\n");
      printf("2\n");
      printf("%I64d %I64d\n", x, y);
    }
  }
  return 0;
}
