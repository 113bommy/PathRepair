#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const int mo = 1000000007;
char s[N];
int n, digcnt;
int op[N], opcnt;
int power(int x, int y) {
  int s = 1;
  for (; y; y /= 2, x = 1ll * x * x % mo)
    if (y & 1) s = 1ll * s * x % mo;
  return s;
}
struct node {
  int x, y, l, p;
  node operator+(const node &b) const {
    node ans, a = *this;
    ans.x = (1ll * a.x * b.p + b.x) % mo;
    ans.y = ans.l = -1;
    ans.p = 1ll * a.p * b.p % mo;
    return ans;
  }
  node operator*(const node &b) const {
    node ans, a = *this;
    if (b.p == 1)
      ans.x = 1ll * a.x * b.x % mo;
    else
      ans.x =
          1ll * (power(b.p, a.y) - 1) * power(b.p - 1, mo - 2) % mo * b.x % mo;
    ans.y = ans.l = -1;
    ans.p = power(b.p, a.y);
    return ans;
  }
  node operator^(const node &b) const {
    node ans, a = *this;
    int v = power(a.p, mo - 2);
    if (v == 1)
      ans.x = 1ll * (a.x + b.x) * (b.x - a.x + 1) / 2 % mo;
    else {
      ans.x = (1ll * b.x * power(v, b.y + 1) + mo -
               1ll * a.x * power(v, a.y) % mo) %
              mo;
      ans.x = (ans.x + mo -
               1ll * (power(v, b.y + 1) + mo - power(v, a.y + 1)) *
                   power(v - 1, mo - 2) % mo) %
              mo;
      ans.x = 1ll * ans.x * power(v - 1, mo - 2) % mo;
    }
    ans.x = 1ll * ans.x * power(power(v, b.y), mo - 2) % mo;
    ans.x = (ans.x + mo) % mo;
    ans.y = ans.l = -1;
    ans.p = power(p, b.y - a.y + 1 + mo - 1);
    return ans;
  }
} L[N], R[N], dig[N];
node func(node a, node b) {
  if (a.l == b.l) return a ^ b;
  node ans = a ^ R[a.l];
  for (int i = (int)(a.l + 1); i <= (int)(b.l - 1); i++)
    ans = ans + (L[i] ^ R[i]);
  ans = ans + (L[b.l] ^ b);
  return ans;
}
node add(node x, int v) {
  node ans;
  ans.x = (10ll * x.x + v) % mo;
  ans.y = (10ll * x.y + v) % (mo - 1);
  ans.l = x.l + 1;
  ans.p = 10ll * x.p % mo;
  return ans;
}
node get(int l, int r) {
  node ans = (node){0, 0, 0, 1};
  for (int i = (int)(l); i <= (int)(r); i++) ans = add(ans, s[i] - '0');
  return ans;
}
int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  L[1] = (node){1, 1, 1, 10};
  R[1] = (node){9, 9, 1, 10};
  for (int i = (int)(2); i <= (int)(n); i++) {
    L[i] = add(L[i - 1], 0);
    R[i] = add(R[i - 1], 9);
  }
  int opcnt = 0;
  int digcnt = 0;
  for (int i = (int)(1); i <= (int)(n); i++) {
    if (s[i] == '(')
      op[++opcnt] = -1;
    else if (s[i] == ')')
      op[++opcnt] = -2;
    else if (s[i] == '+')
      op[++opcnt] = -3;
    else {
      int j = i;
      for (; j <= n && s[j] >= '0' && s[j] <= '9'; j++)
        ;
      if (j > n || s[j] != '-')
        dig[++digcnt] = get(i, j - 1), i = j - 1;
      else {
        int k = j + 1;
        for (; k <= n && s[k] >= '0' && s[k] <= '9'; k++)
          ;
        dig[++digcnt] = func(get(i, j - 1), get(j + 1, k - 1));
        i = k - 1;
      }
      op[++opcnt] = digcnt;
    }
  }
  n = 0;
  for (int i = (int)(1); i <= (int)(opcnt); i++)
    if (op[i] != -2)
      op[++n] = op[i];
    else {
      dig[++digcnt] = dig[op[n--]];
      for (; op[n] != -1; n--) dig[digcnt] = dig[op[--n]] + dig[digcnt];
      dig[digcnt] = dig[op[n - 1]] * dig[digcnt];
      op[--n] = digcnt;
    }
  node ans = dig[op[1]];
  for (int i = (int)(2); i <= (int)(n); i++) i++, ans = ans + dig[op[i]];
  printf("%d\n", ans.x);
}
