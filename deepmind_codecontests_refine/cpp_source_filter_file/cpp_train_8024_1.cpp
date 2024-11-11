#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
long long readIn() {
  long long a = 0;
  bool positive = true;
  char ch = getchar();
  while (!(ch == '-' || std::isdigit(ch))) ch = getchar();
  if (ch == '-') {
    positive = false;
    ch = getchar();
  }
  while (std::isdigit(ch)) {
    a = a * 10 - (ch - '0');
    ch = getchar();
  }
  return positive ? -a : a;
}
void printOut(long long x) {
  char buffer[20];
  int length = 0;
  if (x < 0)
    putchar('-');
  else
    x = -x;
  do buffer[length++] = -(x % 10) + '0';
  while (x /= 10);
  do putchar(buffer[--length]);
  while (length);
  putchar('\n');
}
const int maxn = int(1e5) + 5;
int n, m, x;
int a[maxn];
class SegTree {
  static inline int code(int l, int r) { return (l + r) | (l != r); }
  struct Node {
    int pre[20];
    int suf[20];
    long long ans;
  } nodes[maxn * 2];
  static long long calc(const Node& lc, const Node& rc, int l, int r, int mid) {
    int asuf[21];
    asuf[0] = 0;
    int apre[21];
    apre[0] = 0;
    int sufsum[21];
    int presum[21];
    for (int i = 0; i < 20; i++)
      if (lc.suf[i]) asuf[++asuf[0]] = lc.suf[i];
    for (int i = 0; i < 20; i++)
      if (rc.pre[i] <= n) apre[++apre[0]] = rc.pre[i];
    if (!asuf[0] && !apre[0]) return 0;
    std::sort(asuf + 1, asuf + 1 + asuf[0]);
    std::sort(apre + 1, apre + 1 + apre[0]);
    asuf[0] = std::unique(asuf + 1, asuf + 1 + asuf[0]) - (asuf + 1);
    apre[0] = std::unique(apre + 1, apre + 1 + apre[0]) - (apre + 1);
    long long ret = 0;
    if (!asuf[0]) {
      presum[1] = a[apre[1]];
      for (int i = 2; i <= apre[0]; i++) presum[i] = presum[i - 1] | a[apre[i]];
      int cnt = 0;
      while (cnt <= apre[0] && (cnt ? presum[cnt] : 0) < x) cnt++;
      if (cnt <= apre[0])
        ret += (long long)(mid - l + 1) * (r - (cnt ? apre[cnt] - 1 : mid));
    } else if (!apre[0]) {
      sufsum[asuf[0]] = a[asuf[asuf[0]]];
      for (int i = asuf[0] - 1; i; i--) sufsum[i] = sufsum[i + 1] | a[asuf[i]];
      int cnt = asuf[0] + 1;
      while (cnt && (cnt <= asuf[0] ? sufsum[cnt] : 0) < x) cnt--;
      if (cnt) ret += (long long)(asuf[cnt] - l + 1) * (r - mid);
    } else {
      sufsum[asuf[0]] = a[asuf[asuf[0]]];
      for (int i = asuf[0] - 1; i; i--) sufsum[i] = sufsum[i + 1] | a[asuf[i]];
      presum[1] = a[apre[1]];
      for (int i = 2; i <= apre[0]; i++) presum[i] = presum[i - 1] | a[apre[i]];
      int cnt = 0;
      for (int i = 1; i <= asuf[0] && cnt <= apre[0]; i++) {
        while (cnt <= apre[0] &&
               (cnt ? (sufsum[i] | presum[cnt]) : sufsum[i]) < x)
          cnt++;
        if (cnt > apre[0]) break;
        ret += (long long)(asuf[i] - (i == 1 ? l - 1 : asuf[i - 1])) *
               (r - (cnt ? apre[cnt] - 1 : mid));
      }
      if (asuf[asuf[0]] != mid) {
        while (cnt <= apre[0] && (cnt ? presum[cnt] : 0) < x) cnt++;
        if (cnt <= apre[0])
          ret += (long long)(mid - asuf[asuf[0]]) *
                 (r - (cnt ? apre[cnt] - 1 : mid));
      }
    }
    return ret;
  }
  void cover(int l, int r) {
    Node& t = nodes[code(l, r)];
    t.ans = a[l] >= x;
    for (int i = 0; i < 20; i++)
      if (a[l] & (1 << i))
        t.pre[i] = l;
      else
        t.pre[i] = n + 1;
    for (int i = 0; i < 20; i++)
      if (a[l] & (1 << i))
        t.suf[i] = l;
      else
        t.suf[i] = 0;
  }
  Node update(const Node& lc, const Node& rc, int l, int r, int mid) {
    Node t;
    for (int i = 0; i < 20; i++) t.pre[i] = std::min(lc.pre[i], rc.pre[i]);
    for (int i = 0; i < 20; i++) t.suf[i] = std::max(lc.suf[i], rc.suf[i]);
    t.ans = lc.ans + rc.ans + calc(lc, rc, l, r, mid);
    return t;
  }
  int g_Pos, g_Val, g_L, g_R;
  long long ans;
  void modify_(int l, int r) {
    if (l == r) {
      a[l] = g_Val;
      cover(l, r);
      return;
    }
    int mid = (l + r) >> 1;
    if (g_Pos <= mid)
      modify_(l, mid);
    else
      modify_(mid + 1, r);
    nodes[code(l, r)] =
        update(nodes[code(l, mid)], nodes[code(mid + 1, r)], l, r, mid);
  }
  Node query_(int l, int r) {
    if (g_L <= l && r <= g_R) {
      const Node& t = nodes[code(l, r)];
      ans += t.ans;
      return t;
    }
    int mid = (l + r) >> 1;
    if (g_R <= mid)
      return query_(l, mid);
    else if (g_L > mid)
      return query_(mid + 1, r);
    else {
      Node L = query_(l, mid);
      Node R = query_(mid + 1, r);
      ans += calc(L, R, std::max(g_L, l), std::min(g_R, r), mid);
      return update(L, R, std::max(g_L, l), std::min(g_R, r), mid);
    }
  }

 public:
  void build(int l, int r) {
    if (l == r) {
      cover(l, r);
      return;
    }
    int mid = (l + r) >> 1;
    build(l, mid);
    build(mid + 1, r);
    nodes[code(l, r)] =
        update(nodes[code(l, mid)], nodes[code(mid + 1, r)], l, r, mid);
  }
  void modify(int pos, int val) {
    g_Pos = pos;
    g_Val = val;
    modify_(1, n);
  }
  long long query(int l, int r) {
    g_L = l;
    g_R = r;
    ans = 0;
    query_(1, n);
    return ans;
  }
} st;
void run() {
  n = readIn();
  m = readIn();
  x = readIn();
  for (int i = 1; i <= n; i++) a[i] = readIn();
  if (!x) {
    while (m--) {
      int type = readIn();
      if (type == 1) {
        int pos = readIn();
        int val = readIn();
      } else if (type == 2) {
        int l = readIn();
        int r = readIn();
        long long len = r - l + 1;
        printOut(len * len >> 1);
      }
    }
  } else {
    st.build(1, n);
    while (m--) {
      int type = readIn();
      if (type == 1) {
        int pos = readIn();
        int val = readIn();
        st.modify(pos, val);
      } else if (type == 2) {
        int l = readIn();
        int r = readIn();
        printOut(st.query(l, r));
      }
    }
  }
}
int main() {
  run();
  return 0;
}
