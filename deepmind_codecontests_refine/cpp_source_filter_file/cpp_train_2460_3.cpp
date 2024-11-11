#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx,tune=native")
using namespace std;
const int M = (1 << 14) + 8;
class DJS {
 private:
  vector<int> arr;

 public:
  inline void init(int n) {
    arr.resize(n);
    iota(begin(arr), end(arr), 0);
  }
  inline void rebuild() { iota(begin(arr), end(arr), 0); }
  inline int query(int x) {
    if (arr[x] != x) arr[x] = query(arr[x]);
    return arr[x];
  }
  inline void merge(int a, int b) { arr[query(a)] = arr[query(b)]; }
} djs;
bool hve[M << 1];
int id[2][M];
bitset<M> me, he;
void init(int);
void parse(const string&, bitset<M>&);
inline int hex2dec(char);
void build(int[], int[], int);
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, ans = 0;
  cin >> n >> m;
  init(m);
  int a = 0, b = 1;
  for (int i = 0; i < n; i++) {
    string ss;
    cin >> ss;
    parse(ss, me);
    build(id[a], id[b], m);
    djs.rebuild();
    bool pre = false;
    for (int j = 0; j < m; j++) {
      if (me[j]) {
        ans++;
        if (pre) {
          djs.merge(id[a][j], id[a][j - 1]);
          ans--;
        } else
          pre = true;
        if (he[j] and djs.query(id[b][j]) != djs.query(id[a][j])) {
          djs.merge(id[b][j], id[a][j]);
          ans--;
        }
      } else
        pre = false;
    }
    swap(me, he);
    swap(a, b);
  }
  cout << ans << '\n';
  return 0;
}
void init(int n) {
  for (int i = 0; i < n; i++) id[0][i] = i;
  for (int i = 0; i < n; i++) id[1][i] = i + n;
  djs.init(2 * n);
}
inline int hex2dec(char c) {
  if (isdigit(c)) return c - '0';
  return c - 'A' + 10;
}
void parse(const string& ss, bitset<M>& ret) {
  int n = ss.size(), cur = 0;
  for (int i = 0; i < n; i++) {
    int a = hex2dec(ss[i]);
    for (int j = 3; j >= 0; j--, cur++) ret[cur] = (a >> j) & 1;
  }
}
void build(int a1[], int a2[], int n) {
  memset(hve, 0, sizeof(hve));
  for (int i = 0; i < n; i++) {
    a2[i] = djs.query(a2[i]);
    hve[a2[i]] = 1;
  }
  int cur = 0;
  for (int i = 0; i < n; i++) {
    while (hve[cur]) cur++;
    a1[i] = cur;
  }
}
