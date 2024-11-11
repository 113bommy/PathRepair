#include <bits/stdc++.h>
using namespace std;
template <class _T>
inline _T sqr(const _T& first) {
  return first * first;
}
template <class _T>
inline string tostr(const _T& a) {
  ostringstream os("");
  os << a;
  return os.str();
}
template <class _T>
inline istream& operator<<(istream& is, const _T& a) {
  is.putback(a);
  return is;
}
const long double PI = 3.1415926535897932384626433832795;
const long double EPS = 1e-11;
struct trp {
  int first, second, z;
};
vector<trp> ans;
trp ma;
pair<int, int> a[1024];
int k[1024];
int e[1024];
int n, m;
bool u[1024];
void dfs(int v) {
  u[v] = true;
  ma.second = v;
  if (e[v] == 0) return;
  if (a[v].second < ma.z) {
    ma.z = a[v].second;
  }
  dfs(a[v].first);
}
bool cmp(trp p, trp q) { return p.first < q.first; }
int main() {
  cout << setiosflags(ios::fixed) << setprecision(10);
  scanf("%d%d", &n, &m);
  memset((a), 0, sizeof(a));
  memset((k), 0, sizeof(k));
  memset((e), 0, sizeof(e));
  for (int i = 0; i < m; i++) {
    int first, second, w;
    scanf("%d%d%d", &first, &second, &w);
    first--;
    second--;
    a[first] = make_pair(second, w);
    k[second]++;
    e[first]++;
  }
  memset((u), 0, sizeof(u));
  for (int i = 0; i < n; i++) {
    if (!u[i] && k[i] == 0) {
      ma.first = i;
      ma.second = -1;
      ma.z = 10050000;
      dfs(i);
      if (ma.second != -1) ans.push_back(ma);
    }
  }
  sort(ans.begin(), ans.end(), cmp);
  printf("%d\n", ans.size());
  for (int i = 0; i < (int)ans.size(); i++) {
    printf("%d %d %d\n", ans[i].first + 1, ans[i].second + 1, ans[i].z);
  }
  return 0;
}
