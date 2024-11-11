#include <bits/stdc++.h>
using namespace std;
template <typename T>
void maxtt(T& t1, T t2) {
  t1 = max(t1, t2);
}
template <typename T>
void mintt(T& t1, T t2) {
  t1 = min(t1, t2);
}
bool debug = 0;
int n, m, k;
string direc = "URDL";
const long long MOD2 = (long long)1000000007 * (long long)1000000007;
long long ln, lk, lm;
void etp(bool f = 0) {
  puts(f ? "YES" : "NO");
  exit(0);
}
void addmod(int& x, int y, int mod = 1000000007) {
  assert(y >= 0);
  x += y;
  if (x >= mod) x -= mod;
  assert(x >= 0 && x < mod);
}
void et(int x = -1) {
  printf("%d\n", x);
  exit(0);
}
long long fastPow(long long x, long long y, int mod = 1000000007) {
  long long ans = 1;
  while (y > 0) {
    if (y & 1) ans = (x * ans) % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}
long long gcd1(long long x, long long y) { return y ? gcd1(y, x % y) : x; }
int a[500135], cnt[500135], M, ps[500135], pre[500135];
long long ans;
pair<int, int> b1, b2;
void upt(pair<int, int> z) {
  if (z > b1) {
    b2 = b1;
    b1 = z;
  } else
    maxtt(b2, z);
}
void uptAns(long long x, long long y) {
  if (x >= 2) maxtt(ans, x * y);
}
void fmain(int tid) {
  scanf("%d", &n);
  for (int(i) = 1; (i) <= (int)(n); (i)++) {
    scanf("%d", a + i);
    cnt[a[i]]++;
    maxtt(M, a[i]);
  }
  for (int(i) = 1; (i) <= (int)(M); (i)++) {
    ps[i] = ps[i - 1] + cnt[i];
    pre[i] = pre[i - 1];
    if (cnt[i]) pre[i] = i;
  }
  for (int y = 2; y <= M; y++) {
    long long cntY = 0;
    for (int i = y; i <= M; i += y) {
      cntY += (long long)(ps[min(i + y - 1, M)] - ps[i - 1]) * (i / y);
    }
    b1 = {-1, -1};
    b2 = {-1, -1};
    for (int k = M / y, R = M + 1; k >= 0; R = k * y, k--) {
      int ky = k * y, ss = (b1.first >= 0) + (b2.first >= 0);
      if (pre[R - 1] >= ky) {
        pair<int, int> key = {pre[R - 1] % y, pre[R - 1]};
        upt(key);
        if (cnt[pre[R - 1]] > 1)
          upt(key);
        else {
          int tmp = pre[pre[R - 1]];
          if (tmp >= ky) upt({tmp % y, tmp});
        }
      }
      if (b1.first >= 0) {
        uptAns(min((long long)(b1.first + ky) / 2, cntY - k), y);
      }
      if (b2.second >= 0) {
        uptAns(min((long long)(b2.first + ky), cntY - k - k), y);
        if ((b1.second < R) + ss >= 2) {
          uptAns(min((long long)(b1.first + ky), cntY - k - k - 1), y);
        }
      }
    }
  }
  printf("%lld\n", ans);
}
int main() {
  int t = 1;
  for (int(i) = 1; (i) <= (int)(t); (i)++) {
    fmain(i);
  }
  return 0;
}
