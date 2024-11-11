#include <bits/stdc++.h>
using namespace std;
const int MAX_MEM = 1e8;
int mpos = 0;
char mem[MAX_MEM];
inline void *operator new(size_t n) {
  assert((mpos += n) <= MAX_MEM);
  return (void *)(mem + mpos - n);
}
inline void operator delete(void *) noexcept {}
const int N = 2e5 + 47;
int A[N];
bool used[N];
pair<int, int> E[N];
vector<int> G[N];
int sums[N];
int h[N];
int ans[N];
int p[N], rk[N];
void init(int n) {
  for (int i = 0; i < n; i++) {
    p[i] = i;
    rk[i] = 0;
  }
}
int get(int i) { return p[i] == i ? i : (p[i] = get(p[i])); }
bool join(int a, int b) {
  a = get(a);
  b = get(b);
  if (a == b) return false;
  if (rk[a] > rk[b]) swap(a, b);
  if (rk[a] == rk[b]) rk[b]++;
  p[a] = b;
  return true;
}
void dfs(int v, int p) {
  sums[v] = A[v];
  for (int i = 0; i < G[v].size(); i++) {
    if (G[v][i] == p) continue;
    h[G[v][i]] = h[v] + 1;
    dfs(G[v][i], v);
    sums[v] += sums[G[v][i]];
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  memset(used, 0, sizeof(used));
  int n, m;
  cin >> n;
  long long sumv = 0;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    sumv += A[i];
  }
  if (sumv) {
    cout << "Impossible\n";
    return 0;
  }
  memset(ans, 0, sizeof(ans));
  init(n);
  cin >> m;
  int a, b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    a--;
    b--;
    E[i].first = a;
    E[i].second = b;
    if (join(a, b)) {
      used[i] = true;
      G[a].push_back(b);
      G[b].push_back(a);
    }
  }
  h[0] = 0;
  dfs(0, -1);
  cout << "Possible\n";
  for (int i = 0; i < m; i++) {
    if (used[i]) {
      if (h[E[i].first] > h[E[i].second]) {
        ans[i] = -sums[E[i].first];
      } else {
        ans[i] = sums[E[i].second];
      }
    }
  }
  for (int i = 0; i < m; i++) {
    cout << ans[i] << "\n";
  }
  cout << "\n";
  return 0;
}
