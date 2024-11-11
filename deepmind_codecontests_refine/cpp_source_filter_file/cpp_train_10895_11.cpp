#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
struct base {
  long long b[30], size;
  void ins(long long num) {
    for (long long i = 23; i >= 0; i--) {
      if (num & (1 << i)) {
        if (b[i] == 0) {
          b[i] = num;
          this->size++;
          break;
        } else {
          num ^= b[i];
        }
      }
    }
  }
  void maintain() {
    for (int i = 0; i <= 23; i++) {
      for (int j = i + 1; j <= 23; j++) {
        if (b[j] & (1 << i)) {
          b[j] ^= b[i];
        }
      }
    }
  }
  long long test(long long num) {
    for (int i = 23; i >= 0; i--) {
      if (num & (1 << i)) num ^= b[i];
    }
    return num;
  }
};
void copy_base(base a, base &b) {
  memcpy(b.b, a.b, sizeof a.b);
  b.size = a.size;
}
base data[100005];
int n, q;
int ksm(long long x, int y) {
  long long ret = 1;
  while (y) {
    if (y & 1) ret = (ret * x) % MOD;
    x = (x * x) % MOD;
    y >>= 1;
  }
  return ret;
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    int tmp;
    scanf("%d", &tmp);
    copy_base(data[i - 1], data[i]);
    data[i].ins(tmp);
    data[i].maintain();
  }
  for (int i = 1; i <= q; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (b == 0) {
      if (a > data[a].size) {
        printf("%d\n", ksm(2, a - data[a].size));
      } else {
        puts("0");
      }
    } else {
      int value = data[a].test(b);
      if (value == 0) {
        printf("%d\n", ksm(2, a - data[a].size));
      } else {
        puts("0");
      }
    }
  }
  return 0;
}
