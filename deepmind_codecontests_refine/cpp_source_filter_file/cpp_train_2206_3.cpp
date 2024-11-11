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
      st[p] = A[p1] >= A[p2] ? p1 : p2;
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
    return (A[p1] >= A[p2] ? p1 : p2);
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
      if (p1 >= 0 && p2 >= 0) st[pos] = A[p1] >= A[p2] ? p1 : p2;
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
string getString(char x) {
  string s(1, x);
  return s;
}
string s, t;
bool valid(int f, int l) {
  int k = 0;
  for (int i = f; i <= l; i++) {
    bool fl = false;
    for (; k < s.length(); k++) {
      if (s[k] == t[i]) {
        k++;
        fl = true;
        break;
      }
    }
    if (!fl) return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    int als[26];
    for (int i = 0; i < 26; i++) als[i] = 0;
    int alt[26];
    for (int i = 0; i < 26; i++) alt[i] = 0;
    int n;
    cin >> n;
    cin >> s >> t;
    for (int i = 0; i < n; i++) {
      alt[t[i] - 96]++;
      als[s[i] - 96]++;
    }
    bool fl = true;
    for (int i = 0; i < 26; i++)
      if (alt[i] != als[i]) fl = false;
    if (!fl) {
      cout << -1 << endl;
      continue;
    }
    int mx = 1;
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        if (valid(i, j))
          mx = max(mx, j - i + 1);
        else
          break;
    cout << n - mx << endl;
  }
  return 0;
}
