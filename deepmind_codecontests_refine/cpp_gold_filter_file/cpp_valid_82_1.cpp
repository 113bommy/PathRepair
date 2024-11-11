#include <bits/stdc++.h>
using namespace std;
template <class T>
T gcd(T a, T b) {
  return (b == 0 ? a : gcd(b, a % b));
}
int gi() {
  int a;
  scanf("%d", &a);
  return a;
}
long long gli() {
  long long a;
  scanf("%I64d", &a);
  return a;
}
int cases() {
  static int t = gi();
  return t--;
}
char a[300004];
int s[300004];
int samesign(int a, int b) {
  return (a < 0 ? (b < 0 ? 1 : 0) : (b > 0 ? 1 : 0));
}
int comp(int l, int r) {
  int lsum = -(s[r] - s[l + 1]);
  if (lsum == 0) return l;
  int rsum = s[r - 1] - s[l];
  if (rsum == 0) return r - 1;
  int L = l + 1, R = r - 2;
  while (L < R) {
    int M = (L + R) / 2;
    int sum = s[M] - s[l] - (s[r] - s[M + 1]);
    if (sum == 0) return M;
    if (samesign(sum, lsum)) {
      L = M + 1;
    } else {
      R = M - 1;
    }
  }
  return L;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while (cases()) {
    int n = gi();
    int q = gi();
    scanf("%s", a);
    s[0] = 0;
    for (int i = 0; i < n; i++)
      s[i + 1] = s[i] + (a[i] == '+' ? 1 : -1) * (i % 2 ? 1 : -1);
    for (int i = 0; i < q; i++) {
      int l = gi() - 1;
      int r = gi();
      if ((r - l) % 2 == 0) {
        if (s[r] - s[l] == 0) {
          printf("0\n");
        } else {
          int w = comp(l + 1, r);
          printf("2\n%d %d\n", l + 1, w + 1);
        }
      } else {
        int w = comp(l, r);
        printf("1\n%d\n", w + 1);
      }
    }
  }
  return 0;
}
