#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int T = 20;
const int INF = 1e9;
int n, k;
int a[N];
int step[N];
pair<int, int> g[T][N];
vector<int> add[N];
vector<int> sub[N];
int st[N];
long long sum[N];
int cnt[N];
pair<int, int> getMax(int l, int r) {
  int len = r - l;
  return max(g[st[len]][l], g[st[len]][r - (1 << st[len])]);
}
long long getSum(int l, int r) { return sum[r] - sum[l]; }
void calc(int l, int r) {
  if (l >= r) return;
  auto res = getMax(l, r);
  int x = res.second;
  int len = r - l;
  if ((x - l) * 2 < len) {
    for (int i = l; i <= x; i++) {
      long long s = (k - getSum(i, x) % k + sum[x + 1]) % k;
      add[r + 1].push_back(s);
      sub[x + 1].push_back(s);
    }
  } else {
    for (int i = x; i < r; i++) {
      long long s = (getSum(x + 1, i + 1) + sum[x]) % k;
      add[x + 1].push_back(s);
      sub[l].push_back(s);
    }
  }
  calc(l, x);
  calc(x + 1, r);
}
void read() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
}
void solve() {
  for (int i = 0; i < n; i++) g[0][i] = make_pair(a[i], i);
  for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + a[i];
  for (int j = 1; j < T; j++)
    for (int i = 0; i + (1 << j) <= n; i++)
      g[j][i] = max(g[j - 1][i], g[j - 1][i + (1 << (j - 1))]);
  for (int i = 2; i <= n; i++) st[i] = st[i / 2] + 1;
  calc(0, n);
  long long answer = 0;
  for (int i = 0; i <= n + 1; i++) {
    for (auto x : sub[i]) answer -= cnt[x];
    for (auto x : add[i]) answer += cnt[x];
    cnt[sum[i] % k]++;
  }
  cout << answer - n << endl;
}
void printAns() {}
void stress() {}
int main() {
  if (1) {
    int k = 1;
    for (int tt = 0; tt < k; tt++) {
      read();
      solve();
      printAns();
    }
  } else {
    stress();
  }
  return 0;
}
