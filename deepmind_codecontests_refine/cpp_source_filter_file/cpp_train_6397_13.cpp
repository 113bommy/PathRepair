#include <bits/stdc++.h>
using namespace std;
struct SuffixArray {
  string a;
  int N, m;
  vector<int> SA, LCP, first, second, w, c;
  SuffixArray(string _a, int m = 256)
      : a(" " + _a),
        N(a.length()),
        m(m),
        SA(N),
        LCP(N),
        first(N),
        second(N),
        w(max(m, N)),
        c(N) {
    a[0] = 0;
    DA();
    kasaiLCP();
    {
      rotate(SA.begin(), SA.begin() + 1, SA.end());
      SA.pop_back();
    };
    {
      rotate(LCP.begin(), LCP.begin() + 1, LCP.end());
      LCP.pop_back();
    };
    a = a.substr(1, a.size());
    for (int i = 0; i < (int)SA.size(); ++i) --SA[i];
  }
  inline bool cmp(const int a, const int b, const int l) {
    return (second[a] == second[b] && second[a + l] == second[b + l]);
  }
  void Sort() {
    for (int i = 0; i < m; ++i) w[i] = 0;
    for (int i = 0; i < N; ++i) ++w[first[second[i]]];
    for (int i = 0; i < m - 1; ++i) w[i + 1] += w[i];
    for (int i = N - 1; i >= 0; --i) SA[--w[first[second[i]]]] = second[i];
  }
  void DA() {
    for (int i = 0; i < N; ++i) first[i] = a[i], second[i] = i;
    Sort();
    for (int i, j = 1, p = 1; p < N; j <<= 1, m = p) {
      for (p = 0, i = N - j; i < N; i++) second[p++] = i;
      for (int k = 0; k < N; ++k)
        if (SA[k] >= j) second[p++] = SA[k] - j;
      Sort();
      for (swap(first, second), p = 1, first[SA[0]] = 0, i = 1; i < N; ++i)
        first[SA[i]] = cmp(SA[i - 1], SA[i], j) ? p - 1 : p++;
    }
  }
  void kasaiLCP() {
    for (int i = 0; i < N; i++) c[SA[i]] = i;
    for (int i = 0, j, k = 0; i < N; LCP[c[i++]] = k)
      if (c[i] > 0)
        for (k ? k-- : 0, j = SA[c[i] - 1]; a[i + k] == a[j + k]; k++)
          ;
      else
        k = 0;
  }
};
string s[3];
int stringId(int id) {
  if (id >= 0 && id < s[0].size()) return 0;
  if (id > s[0].size() && id < s[0].size() + s[1].size() + 1) return 1;
  if (id > s[0].size() + s[1].size() + 1 &&
      id < s[0].size() + s[1].size() + s[2].size() + 2)
    return 2;
  return -1;
}
const int N = 300005;
const int MOD = 1000000007;
int cnt[N][3];
int p[N];
vector<int> v[N];
int l;
int ans[N];
int root(int first) {
  return ((p[first] == first) ? first : p[first] = root(p[first]));
}
void merge(int u, int v, int &plus) {
  if ((u = root(u)) == (v = root(v))) return;
  long long temp = 0;
  temp -= 1LL * cnt[u][0] * cnt[u][1] * cnt[u][2] % MOD;
  temp -= 1LL * cnt[v][0] * cnt[v][1] * cnt[v][2] % MOD;
  p[v] = u;
  for (int i = 0; i < 3; i++) cnt[u][i] += cnt[v][i];
  temp += 1LL * cnt[u][0] * cnt[u][1] * cnt[u][2] % MOD;
  temp = (temp % MOD + MOD) % MOD;
  plus += temp;
  plus %= MOD;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> s[0] >> s[1] >> s[2];
  l = min(s[0].size(), min(s[1].size(), s[2].size()));
  string t = s[0] + "$" + s[1] + "&" + s[2];
  SuffixArray sa = SuffixArray(t);
  int n = t.size();
  for (int i = 0; i < n; i++) {
    p[i] = i;
    int foo = stringId(sa.SA[i]);
    if (foo != -1) cnt[i][foo] = 1;
    v[sa.LCP[i]].push_back(i);
  }
  int plus = 0;
  for (int i = l; i >= 1; i--) {
    for (int e : v[i]) {
      merge(e - 1, e, plus);
    }
    ans[i] = (ans[i + 1] + plus) % MOD;
    plus = 0;
  }
  for (int i = 1; i <= l; i++) cout << ans[i] << ' ';
  return 0;
}
