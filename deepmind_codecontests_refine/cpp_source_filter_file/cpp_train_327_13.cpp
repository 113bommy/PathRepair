#include <bits/stdc++.h>
using namespace std;
class SegTree {
 public:
  vector<long long> A;
  vector<long long> st;
  int n;
  int left(int i) { return (i << 1); }
  int right(int i) { return (i << 1) + 1; }
  void build(int p, int L, int R) {
    if (L == R)
      st[p] = L;
    else {
      build(left(p), L, (L + R) / 2);
      build(right(p), (L + R) / 2 + 1, R);
      int p1 = st[left(p)];
      int p2 = st[right(p)];
      st[p] = A[p1] <= A[p2] ? p1 : p2;
    }
  }
  SegTree(const vector<long long> &_A) {
    A = _A;
    n = _A.size();
    st.assign(4 * n, -1);
    build(1, 0, n - 1);
  }
  int rmq(int p, int L, int R, int i, int j) {
    if (i > R || j < L) return -1;
    if (L >= i && R <= j) return st[p];
    int p1 = rmq(left(p), L, (L + R) / 2, i, j);
    int p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);
    if (p1 == -1) return p2;
    if (p2 == -1) return p1;
    return (A[p1] <= A[p2] ? p1 : p2);
  }
  int rmq(int i, int j) {
    if (i < 0) i = 0;
    return rmq(1, 0, n - 1, i, j);
  }
  int getIndex(int p, int L, int R, int pos) {
    if (L == R) return p;
    if (pos <= (L + R) / 2) return getIndex(left(p), L, (L + R) / 2, pos);
    return getIndex(right(p), (L + R) / 2 + 1, R, pos);
  }
  void update(int pos, int value) {
    A[pos] = value;
    pos = getIndex(1, 0, n - 1, pos);
    pos /= 2;
    while (pos != 0) {
      int p1 = st[left(pos)];
      int p2 = st[right(pos)];
      if (p1 >= 0 && p2 >= 0) st[pos] = A[p1] <= A[p2] ? p1 : p2;
      pos /= 2;
    }
  }
};
class UnionFind {
 public:
  vector<int> rank;
  vector<pair<int, int> > p;
  UnionFind(int N) {
    rank.assign(N, 0);
    p.assign(N, pair<int, int>(0, 1));
    for (int i = 0; i < N; i++) p[i].first = i;
  }
  int findSet(int i) {
    return (p[i].first == i) ? i : (p[i].first = findSet(p[i].first));
  }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) {
      int x = findSet(i), y = findSet(j);
      if (rank[x] > rank[y]) {
        p[y].first = x;
        p[x].second += p[y].second;
      } else {
        p[x].first = y;
        p[y].second += p[x].second;
        if (rank[x] == rank[y]) rank[y]++;
      }
    }
  }
  int getMaxId() {
    int maxIn = 0;
    for (int i = 0; i < p.size(); i++)
      if (p[i].second > p[maxIn].second) maxIn = i;
    return maxIn;
  }
  int getNum() {
    set<int> par;
    for (int i = 0; i < p.size(); i++) par.insert(p[i].first);
    return par.size();
  }
};
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    string str;
    cin >> str;
    int n = str.length();
    n++;
    str = " " + str;
    int dpX[n];
    int dpY[n];
    dpY[0] = dpX[0] = 0;
    int mnX = 0, mxX = 0, mnY = 0, mxY = 0;
    for (int i = 1; i < n; i++) {
      dpX[i] = dpX[i - 1];
      dpY[i] = dpY[i - 1];
      if (str[i] == 'D') dpX[i]++;
      if (str[i] == 'A') dpX[i]--;
      if (str[i] == 'W') dpY[i]++;
      if (str[i] == 'S') dpY[i]--;
      mnX = min(mnX, dpX[i]);
      mxX = max(mxX, dpX[i]);
      mnY = min(mnY, dpY[i]);
      mxY = max(mnX, dpY[i]);
    }
    int fmxX, lmxX, fmnX, lmnX;
    int fmxY, lmxY, fmnY, lmnY;
    fmxX = lmxX = fmnX = lmxX = fmxY = lmxY = fmnY = lmxY = -1;
    for (int i = 0; i < n; i++) {
      if (dpX[i] == mxX) {
        lmxX = i;
        if (fmxX == -1) fmxX = i;
      }
      if (dpX[i] == mnX) {
        lmnX = i;
        if (fmnX == -1) fmnX = i;
      }
      if (dpY[i] == mxY) {
        lmxY = i;
        if (fmxY == -1) fmxY = i;
      }
      if (dpY[i] == mnY) {
        lmnY = i;
        if (fmnY == -1) fmnY = i;
      }
    }
    bool x = (lmnX + 1 < fmxX || lmxX + 1 < fmnX);
    bool y = (lmnY + 1 < fmxY || lmxY + 1 < fmnY);
    int disX = mxX - mnX + 1;
    int disY = mxY - mnY + 1;
    if (disX <= 2) x = false;
    if (disY <= 2) y = false;
    if (disX >= disY) {
      if (y)
        disY--;
      else if (x)
        disX--;
    } else {
      if (x)
        disX--;
      else if (y)
        disY--;
    }
    long long res = ((long long)disX) * disY;
    cout << res << endl;
  }
}
