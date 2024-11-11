#include <bits/stdc++.h>
using namespace std;
vector<int> v[1000010];
long long JC[1000010];
int num_p[1000010], num_m[1000010], a[1000010], m[1000010], f[1000010],
    g[1000010], n;
void prepare() {
  JC[0] = 1;
  for (int i = 1; i <= n; i++) JC[i] = (JC[i - 1] * i) % 1000000007;
  for (int i = 1; i <= n; i++) m[i] = 1;
  for (int i = 2; i <= n; i++)
    if (v[i].size() == 0) {
      num_p[n / i]++;
      for (int j = i; j <= n; j += i) v[j].push_back(i), m[j] *= i;
    }
  for (int i = 1; i <= n; i++) num_m[m[i]]++;
  num_p[1]++, v[1].push_back(1);
}
void No_answer() {
  cout << 0 << endl;
  exit(0);
}
int get_num(int x) { return (x == 1) ? 1 : (n / x); }
int pan(int a, int b) {
  if (v[a].size() != v[b].size()) return 0;
  for (int i = 0; i < v[b].size() - 1; i++)
    if (v[a][i] != v[b][i]) return 0;
  int x = v[a].back(), y = v[b].back();
  if (get_num(x) != get_num(y)) return 0;
  if ((f[y] > 0) && (f[y] != x)) return 0;
  if ((g[x] > 0) && (g[x] != y)) return 0;
  if ((f[y] == 0) && (g[x] == 0)) num_m[get_num(x)]--;
  f[y] = x, g[x] = y;
}
int main() {
  cin >> n;
  prepare();
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) continue;
    num_p[a[i]]--;
    if (!pan(a[i], i)) No_answer();
  }
  long long ans = 1;
  for (int i = 1; i <= n; i++)
    ans = ans * JC[num_p[i]] % 1000000007 * JC[num_m[i]] % 1000000007;
  cout << ans << endl;
}
