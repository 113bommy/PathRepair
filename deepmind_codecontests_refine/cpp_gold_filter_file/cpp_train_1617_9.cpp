#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T BM(T p, T e, T M) {
  long long int ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return (T)ret;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T mdINV(T a, T M) {
  return BM(a, M - 2, M);
}
template <class T>
inline T PW(T p, T e) {
  long long int ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p);
    p = (p * p);
  }
  return (T)ret;
}
template <class T>
string NTS(T Number) {
  stringstream ss;
  ss << Number;
  return ss.str();
}
template <class T>
T stringtonumber(const string &Text) {
  istringstream ss(Text);
  T result;
  return ss >> result ? result : 0;
}
template <class T>
bool ISLEFT(T a, T b, T c) {
  if (((a.first.first - b.first.first) * (b.second.second - c.second.second) -
       (b.first.first - c.first.first) * (a.second.second - b.second.second)) <
      0.0)
    return 1;
  else
    return 0;
}
bool prv[1002];
int n, m, sz;
bitset<1001> bt;
void seive() {
  prv[1] = 1;
  for (int i = 2; i <= m; i++) {
    if (prv[i] == 0)
      for (int j = i * 2; j <= m; j += i) {
        prv[j] = 1;
      }
  }
  for (int i = 2; i < m; i++)
    if (prv[i] == 0) bt.set(i);
}
int a[100000 + 2];
vector<int> v[100000 + 2];
pair<int, int> ar[100000 + 2];
int kon[100000 + 2];
void dfs(int i, int p) {
  ar[i].first = ++sz;
  kon[sz] = i;
  for (int j = 0; j < v[i].size(); j++) {
    int first = v[i][j];
    if (first == p) continue;
    dfs(first, i);
  }
  ar[i].second = sz;
}
bitset<1001> tr[100000 * 4];
int lazy[100000 * 4];
void build(int no, int s, int e) {
  if (s == e) {
    tr[no].set(a[kon[s]] % m);
    return;
  }
  int mid = (s + e) >> 1;
  build(no * 2, s, mid);
  build(no * 2 + 1, mid + 1, e);
  tr[no] = tr[no * 2] | tr[no * 2 + 1];
}
void propagate(bitset<1001> &first, int l) {
  first = ((first << l)) | (first >> (m - l));
}
void update(int no, int s, int e, int st, int en, int val) {
  if (lazy[no]) {
    propagate(tr[no], lazy[no]);
    if (s != e) {
      lazy[no * 2] = (lazy[no * 2] + lazy[no]) % m;
      lazy[no * 2 + 1] = (lazy[no * 2 + 1] + lazy[no]) % m;
    }
    lazy[no] = 0;
  }
  if (e < st || s > en) return;
  if (s >= st && e <= en) {
    lazy[no] = (lazy[no] + val) % m;
    propagate(tr[no], lazy[no]);
    if (s != e) {
      lazy[no * 2] = (lazy[no * 2] + lazy[no]) % m;
      lazy[no * 2 + 1] = (lazy[no * 2 + 1] + lazy[no]) % m;
    }
    lazy[no] = 0;
    return;
  }
  int mid = (s + e) >> 1;
  update(no * 2, s, mid, st, en, val);
  update(no * 2 + 1, mid + 1, e, st, en, val);
  tr[no] = tr[no * 2] | tr[no * 2 + 1];
}
bitset<1001> now;
void query(int no, int s, int e, int st, int en) {
  if (lazy[no]) {
    propagate(tr[no], lazy[no]);
    if (s != e) {
      lazy[no * 2] = (lazy[no * 2] + lazy[no]) % m;
      lazy[no * 2 + 1] = (lazy[no * 2 + 1] + lazy[no]) % m;
    }
    lazy[no] = 0;
  }
  if (e < st || s > en) return;
  if (s >= st && e <= en) {
    now |= tr[no];
    return;
  }
  int mid = (s + e) >> 1;
  query(no * 2, s, mid, st, en);
  query(no * 2 + 1, mid + 1, e, st, en);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), a[i] %= m;
  seive();
  for (int j = 1; j < n; j++) {
    int first, second;
    scanf("%d%d", &first, &second);
    v[first].push_back(second);
    v[second].push_back(first);
  }
  dfs(1, 0);
  build(1, 1, n);
  int q;
  scanf("%d", &q);
  while (q--) {
    int ty;
    scanf("%d", &ty);
    if (ty == 1) {
      int first, second;
      scanf("%d%d", &first, &second);
      second %= m;
      update(1, 1, n, ar[first].first, ar[first].second, second);
    } else {
      int first;
      scanf("%d", &first);
      now.reset();
      query(1, 1, n, ar[first].first, ar[first].second);
      int ans = (now & bt).count();
      printf("%d\n", ans);
    }
  }
  return 0;
}
