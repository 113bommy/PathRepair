#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 62;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= 1000000007;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % 1000000007;
    a = a * a % 1000000007;
  }
  return res;
}
template <typename T>
inline bool chkmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline bool chkmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int blo[500005];
struct node {
  int l, r, id;
  node() {}
  node(int _l, int _r, int _id) : l(_l), r(_r), id(_id) {}
  bool operator<(const node &x) const {
    return blo[l] == blo[x.l] ? r < x.r : blo[l] < blo[x.l];
  }
} q[500005];
const int sqrtn = 333;
int n, m;
int a[500005], ans[500005];
int num1[500005], num2[500005];
int cnt[500005];
vector<int> big;
void add(int x, int y) {
  --num2[num1[a[x]]];
  num1[a[x]] += y;
  ++num2[num1[a[x]]];
}
int calc() {
  static int tmp[sqrtn + 2];
  memcpy(tmp, num2, sizeof tmp);
  priority_queue<int, vector<int>, greater<int> > BIG;
  int lst = 0, res = 0;
  for (int i = 1; i < sqrtn; i++)
    if (tmp[i]) {
      if (lst) {
        res += lst + i;
        --tmp[i];
        if (lst + i >= sqrtn)
          BIG.push(lst + i);
        else
          ++tmp[lst + i];
        lst = 0;
      }
      res += i * (tmp[i] - (tmp[i] & 1));
      if ((i << 1) >= sqrtn) {
        for (int j = 0; j < (tmp[i] >> 1); j++) BIG.push(i << 1);
      } else
        tmp[i << 1] += tmp[i] >> 1;
      if (tmp[i] & 1) lst = i;
    }
  for (auto v : big)
    if (num1[v] >= sqrtn) BIG.push(num1[v]);
  while (!BIG.empty()) {
    int x = BIG.top();
    BIG.pop();
    if (lst) {
      res += lst + x;
      BIG.push(lst + x);
      lst = 0;
    } else
      lst = x;
  }
  return res;
}
int main() {
  n = read();
  for (int i = 0; i <= n; i++) blo[i] = i / sqrtn;
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    cnt[a[i]]++;
    if (cnt[a[i]] == sqrtn) big.push_back(a[i]);
  }
  m = read();
  for (int i = 0; i < m; i++) {
    q[i].l = read(), q[i].r = read();
    q[i].id = i;
  }
  sort(q, q + m);
  int L = 1, R = 0;
  for (int i = 0; i < m; i++) {
    while (R < q[i].r) add(++R, 1);
    while (L > q[i].l) add(--L, 1);
    while (L < q[i].l) add(L++, -1);
    while (R > q[i].r) add(R--, -1);
    ans[q[i].id] = calc();
  }
  for (int i = 0; i < m; i++) printf("%d\n", ans[i]);
  return 0;
}
