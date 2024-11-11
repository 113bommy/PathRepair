#include <bits/stdc++.h>
using namespace std;
class UnionFind {
 private:
  vector<int> p, rank;

 public:
  UnionFind(int N) {
    rank.assign(N, 0);
    p.assign(N, 0);
    for (int i = 0; i < N; i++) {
      p[i] = i;
    }
  }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) {
      int x = findSet(i), y = findSet(j);
      if (rank[x] > rank[y])
        p[y] = x;
      else {
        p[x] = y;
        if (rank[x] == rank[y]) rank[y]++;
      }
    }
  }
};
class SegmentTree {
 private:
  vector<int> st, A;
  int n;
  int left(int p) { return p << 1; }
  int right(int p) { return (p << 1) + 1; }
  void build(int p, int L, int R) {
    if (L == R)
      st[p] = L;
    else {
      build(left(p), L, (L + R) / 2);
      build(right(p), (L + R) / 2 + 1, R);
      int p1 = st[left(p)], p2 = st[right(p)];
      st[p] = (A[p1] <= A[p2]) ? p1 : p2;
    }
  }
  int rmq(int p, int L, int R, int i, int j) {
    if (i > R || j < L) return -1;
    if (L >= i && R <= j) return st[p];
    int p1 = rmq(left(p), L, (L + R) / 2, i, j);
    int p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);
    if (p1 == -1) return p2;
    if (p2 == -1) return p1;
    return (A[p1] <= A[p2]) ? p1 : p2;
  }
  int update_point(int p, int L, int R, int idx, int new_value) {
    int i = idx, j = idx;
    if (i > R || j < L) return st[p];
    if (L == i && R == j) {
      A[i] = new_value;
      return st[p] = L;
    }
    int p1, p2;
    p1 = update_point(left(p), L, (L + R) / 2, idx, new_value);
    p2 = update_point(right(p), (L + R) / 2 + 1, R, idx, new_value);
    return st[p] = (A[p1] <= A[p2]) ? p1 : p2;
  }

 public:
  SegmentTree(const vector<int> &_A) {
    A = _A;
    n = (int)A.size();
    st.assign(4 * n, 0);
    build(1, 0, n - 1);
  }
  int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }
  int update_point(int idx, int new_value) {
    return update_point(1, 0, n - 1, idx, new_value);
  }
};
class FenwickTree {
 private:
  vector<int> ft;

 public:
  FenwickTree(int n) { ft.assign(n + 1, 0); }
  int rsq(int b) {
    int sum = 0;
    for (; b; b -= (b & (-b))) sum += ft[b];
    return sum;
  }
  void adjust(int k, int v) {
    for (; k < (int)ft.size(); k += (k & (-k))) {
      ft[k] += v;
    }
  }
};
int n, m;
vector<int> v[100005];
int dfs_num[100005];
int dfs_step[100005];
bool z = 0;
int odd = 0, even = 0;
void dfs(int a, int b) {
  dfs_num[a] = 1;
  dfs_step[a] = b;
  if (b % 2)
    odd++;
  else
    even++;
  for (int i = int(0); i <= int(v[a].size() - 1); i++) {
    int next = v[a][i];
    if (dfs_num[next] == 1)
      if ((dfs_step[next] + dfs_step[a]) % 2 == 0) z = 1;
    if (!dfs_num[next]) dfs(next, b + 1);
  }
  dfs_num[a] = 2;
}
int main() {
  scanf("%d", &n);
  scanf("%d", &m);
  int x, y;
  bool larger[100005];
  bool two = 1;
  memset((larger), 0, sizeof(larger));
  for (int i = int(0); i <= int(m - 1); i++) {
    scanf("%d%d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
    if (larger[x] || larger[y]) two = 0;
    larger[x] = 1;
    larger[y] = 1;
  }
  long long ans = 0, tmp = 0;
  long long tmp2, tmp3;
  if (!m) {
    printf("3 ");
    tmp = (long long)n;
    tmp2 = (long long)(n - 1);
    tmp3 = (long long)(n - 2);
    ans = tmp * (tmp - 1) * (tmp - 2) / 6;
  } else if (two) {
    printf("2 ");
    tmp = (long long)(n - 2);
    ans = (long long)(m)*tmp;
  } else {
    memset((dfs_num), 0, sizeof(dfs_num));
    memset((dfs_step), 0, sizeof(dfs_step));
    for (int i = int(1); i <= int(n); i++) {
      if (!dfs_num[i]) {
        odd = even = 0;
        dfs(i, 0);
        tmp = (long long)(odd) * (long long)(odd - 1) / 2;
        ans += tmp;
        tmp = (long long)(even) * (long long)(even - 1) / 2;
        ans += tmp;
      }
    }
    if (z) {
      printf("0 ");
      ans = 1;
    } else
      printf("1 ");
  }
  cout << ans << endl;
  return 0;
}
