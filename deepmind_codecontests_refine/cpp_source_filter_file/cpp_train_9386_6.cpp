#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using std::bitset;
using std::cerr;
using std::cin;
using std::cout;
using std::deque;
using std::endl;
using std::fill;
using std::ios_base;
using std::iterator;
using std::lower_bound;
using std::map;
using std::max_element;
using std::min_element;
using std::multimap;
using std::multiset;
using std::next_permutation;
using std::pair;
using std::queue;
using std::reverse;
using std::set;
using std::sort;
using std::stable_sort;
using std::stack;
using std::string;
using std::swap;
using std::unique;
using std::vector;
long long max(long long a, long long b) {
  if (a > b) return a;
  return b;
}
long long min(long long a, long long b) {
  if (a > b) return b;
  return a;
}
namespace MySpace {};
long long n;
long long a[500000], b[500000], c[500000], d[500000];
map<int, int> chopX, chopY;
const int MAX_N = 1e4 + 2;
struct Node1 {
  int cnt1 = 0, cnt2 = 0, cnt3 = 0;
  Node1 *ls, *rs;
};
struct Node2 {
  Node1* S;
  Node2 *ls, *rs;
};
inline int summ11(int l, int r, int L, int R, Node1* Nd) {
  if (l <= L && R <= r) return Nd->cnt1;
  if (r <= L || R <= l) return 0;
  int M = (L + R) / 2;
  int res = 0;
  if (Nd->ls != nullptr) res += summ11(l, r, L, M, Nd->ls);
  if (Nd->rs != nullptr) res += summ11(l, r, M, R, Nd->rs);
  return res;
}
inline void add11(int p, int L, int R, Node1* Nd) {
  if (L + 1 == R) {
    Nd->cnt1++;
    return;
  }
  int M = (L + R) / 2;
  if (p < M) {
    if (Nd->ls == nullptr) {
      Node1* Ap = new Node1();
      Nd->ls = Ap;
    }
    add11(p, L, M, Nd->ls);
    Nd->cnt1++;
  } else {
    if (Nd->rs == nullptr) {
      Node1* Ap = new Node1();
      Nd->rs = Ap;
    }
    add11(p, M, R, Nd->rs);
    Nd->cnt1++;
  }
}
inline int summ21(int l, int r, int L, int R, Node2* Nd, int thatL, int thatR) {
  if (l <= L && R <= r) return summ11(thatL, thatR, 0, MAX_N, Nd->S);
  if (r <= L || R <= l) return 0;
  int M = (L + R) / 2;
  int res = 0;
  if (Nd->ls != nullptr) res += summ21(l, r, L, M, Nd->ls, thatL, thatR);
  if (Nd->rs != nullptr) res += summ21(l, r, M, R, Nd->rs, thatL, thatR);
  return res;
}
inline void add21(int p, int L, int R, Node2* Nd, int thatP) {
  if (L + 1 == R) {
    add11(thatP, 0, MAX_N, Nd->S);
    return;
  }
  int M = (L + R) / 2;
  if (p < M) {
    if (Nd->ls == nullptr) {
      Node2* Ap = new Node2();
      Ap->S = new Node1();
      Nd->ls = Ap;
    }
    add21(p, L, M, Nd->ls, thatP);
    add11(thatP, 0, MAX_N, Nd->S);
  } else {
    if (Nd->rs == nullptr) {
      Node2* Ap = new Node2();
      Ap->S = new Node1();
      Nd->rs = Ap;
    }
    add21(p, M, R, Nd->rs, thatP);
    add11(thatP, 0, MAX_N, Nd->S);
  }
}
inline int summ12(int l, int r, int L, int R, Node1* Nd) {
  if (l <= L && R <= r) return Nd->cnt2;
  if (r <= L || R <= l) return 0;
  int M = (L + R) / 2;
  int res = 0;
  if (Nd->ls != nullptr) res += summ12(l, r, L, M, Nd->ls);
  if (Nd->rs != nullptr) res += summ12(l, r, M, R, Nd->rs);
  return res;
}
inline void add12(int p, int L, int R, Node1* Nd) {
  if (L + 1 == R) {
    Nd->cnt2++;
    return;
  }
  int M = (L + R) / 2;
  if (p < M) {
    if (Nd->ls == nullptr) {
      Node1* Ap = new Node1();
      Nd->ls = Ap;
    }
    add12(p, L, M, Nd->ls);
    Nd->cnt2++;
  } else {
    if (Nd->rs == nullptr) {
      Node1* Ap = new Node1();
      Nd->rs = Ap;
    }
    add12(p, M, R, Nd->rs);
    Nd->cnt2++;
  }
}
inline int summ22(int l, int r, int L, int R, Node2* Nd, int thatL, int thatR) {
  if (l <= L && R <= r) return summ12(thatL, thatR, 0, MAX_N, Nd->S);
  if (r <= L || R <= l) return 0;
  int M = (L + R) / 2;
  int res = 0;
  if (Nd->ls != nullptr) res += summ22(l, r, L, M, Nd->ls, thatL, thatR);
  if (Nd->rs != nullptr) res += summ22(l, r, M, R, Nd->rs, thatL, thatR);
  return res;
}
inline void add22(int p, int L, int R, Node2* Nd, int thatP) {
  if (L + 1 == R) {
    add12(thatP, 0, MAX_N, Nd->S);
    return;
  }
  int M = (L + R) / 2;
  if (p < M) {
    if (Nd->ls == nullptr) {
      Node2* Ap = new Node2();
      Ap->S = new Node1();
      Nd->ls = Ap;
    }
    add22(p, L, M, Nd->ls, thatP);
    add12(thatP, 0, MAX_N, Nd->S);
  } else {
    if (Nd->rs == nullptr) {
      Node2* Ap = new Node2();
      Ap->S = new Node1();
      Nd->rs = Ap;
    }
    add22(p, M, R, Nd->rs, thatP);
    add12(thatP, 0, MAX_N, Nd->S);
  }
}
inline int summ13(int l, int r, int L, int R, Node1* Nd) {
  if (l <= L && R <= r) return Nd->cnt3;
  if (r <= L || R <= l) return 0;
  int M = (L + R) / 2;
  int res = 0;
  if (Nd->ls != nullptr) res += summ13(l, r, L, M, Nd->ls);
  if (Nd->rs != nullptr) res += summ13(l, r, M, R, Nd->rs);
  return res;
}
inline void add13(int p, int L, int R, Node1* Nd) {
  if (L + 1 == R) {
    Nd->cnt3++;
    return;
  }
  int M = (L + R) / 2;
  if (p < M) {
    if (Nd->ls == nullptr) {
      Node1* Ap = new Node1();
      Nd->ls = Ap;
    }
    add13(p, L, M, Nd->ls);
    Nd->cnt3++;
  } else {
    if (Nd->rs == nullptr) {
      Node1* Ap = new Node1();
      Nd->rs = Ap;
    }
    add13(p, M, R, Nd->rs);
    Nd->cnt3++;
  }
}
inline int summ23(int l, int r, int L, int R, Node2* Nd, int thatL, int thatR) {
  if (l <= L && R <= r) return summ13(thatL, thatR, 0, MAX_N, Nd->S);
  if (r <= L || R <= l) return 0;
  int M = (L + R) / 2;
  int res = 0;
  if (Nd->ls != nullptr) res += summ23(l, r, L, M, Nd->ls, thatL, thatR);
  if (Nd->rs != nullptr) res += summ23(l, r, M, R, Nd->rs, thatL, thatR);
  return res;
}
inline void add23(int p, int L, int R, Node2* Nd, int thatP) {
  if (L + 1 == R) {
    add13(thatP, 0, MAX_N, Nd->S);
    return;
  }
  int M = (L + R) / 2;
  if (p < M) {
    if (Nd->ls == nullptr) {
      Node2* Ap = new Node2();
      Ap->S = new Node1();
      Nd->ls = Ap;
    }
    add23(p, L, M, Nd->ls, thatP);
    add13(thatP, 0, MAX_N, Nd->S);
  } else {
    if (Nd->rs == nullptr) {
      Node2* Ap = new Node2();
      Ap->S = new Node1();
      Nd->rs = Ap;
    }
    add23(p, M, R, Nd->rs, thatP);
    add13(thatP, 0, MAX_N, Nd->S);
  }
}
inline bool solve(int a, int b, int c, int d, Node2* ROOT) {
  if (summ21(a, c, 0, MAX_N, ROOT, b, d) <= 1) return 1;
  long long ans = 0;
  for (int i = a + 1, i2 = c - 1, j = b + 1, j2 = d - 1;
       (a < i && i < c) || (b < j && j < d); i++, i2--, j++, j2--) {
    if (a < i && i < c) {
      int p1 = summ21(a, i, 0, MAX_N, ROOT, b, d);
      int p2 = summ22(a + 1, i + 1, 0, MAX_N, ROOT, b, d);
      if (p1 == p2 && p1 > 0) {
        ans = solve(a, b, i, d, ROOT);
        if (ans == 0) break;
        ans = solve(i, b, c, d, ROOT);
        if (ans == 1) return 1;
        break;
      }
      p1 = summ21(a, i2, 0, MAX_N, ROOT, b, d);
      p2 = summ22(a + 1, i2 + 1, 0, MAX_N, ROOT, b, d);
      if (p1 == p2 && p1 > 0) {
        ans = solve(a, b, i2, d, ROOT);
        if (ans == 0) break;
        ans = solve(i2, b, c, d, ROOT);
        if (ans == 1) return 1;
        break;
      }
    }
    if (b < j && j < d) {
      int p1 = summ21(a, c, 0, MAX_N, ROOT, b, j);
      int p3 = summ23(a, c, 0, MAX_N, ROOT, b + 1, j + 1);
      if (p1 == p3 && p1 > 0) {
        ans = solve(a, b, c, j, ROOT);
        if (ans == 0) break;
        ans = solve(a, j, c, d, ROOT);
        if (ans == 1) return 1;
        break;
      }
      p1 = summ21(a, c, 0, MAX_N, ROOT, b, j2);
      p3 = summ23(a, c, 0, MAX_N, ROOT, b + 1, j2 + 1);
      if (p1 == p3 && p1 > 0) {
        ans = solve(a, b, c, j2, ROOT);
        if (ans == 0) break;
        ans = solve(a, j2, c, d, ROOT);
        if (ans == 1) return 1;
        break;
      }
    }
  }
  for (int j = b + 1; j < d; j++) {
  }
  return 0;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  Node2* ROOT = new Node2();
  ROOT->S = new Node1();
  cin >> n;
  vector<int> vx, vy;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    vx.push_back(a[i]);
    vx.push_back(c[i]);
    vy.push_back(b[i]);
    vy.push_back(d[i]);
  }
  sort(vx.begin(), vx.end());
  sort(vy.begin(), vy.end());
  vx.resize(unique(vx.begin(), vx.end()) - vx.begin());
  vy.resize(unique(vy.begin(), vy.end()) - vy.begin());
  int mx = vx.size(), my = vy.size();
  for (int i = 0; i < vx.size(); i++) {
    chopX[vx[i]] = i + 1;
  }
  for (int i = 0; i < vy.size(); i++) {
    chopY[vy[i]] = i + 1;
  }
  for (int i = 0; i < n; i++) {
    a[i] = chopX[a[i]];
    b[i] = chopY[b[i]];
    c[i] = chopX[c[i]];
    d[i] = chopY[d[i]];
    add21(a[i], 0, MAX_N, ROOT, b[i]);
    add22(c[i], 0, MAX_N, ROOT, b[i]);
    add23(a[i], 0, MAX_N, ROOT, d[i]);
  }
  if (solve(0, 0, mx + 2, my + 2, ROOT) == 1) {
    cout << "YES";
    return 0;
  }
  cout << "NO";
  return 0;
}
