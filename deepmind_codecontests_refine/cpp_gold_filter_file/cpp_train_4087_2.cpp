#include <bits/stdc++.h>
using namespace std;
const int GO_MAX = 26;
const int ESP = 1e-9;
const int MAX = 101001;
const int INF = 1e9;
const int H_val = 37;
const int mod = 1000000;
const double PI = 3.14159265359;
int n, m, k, t, p, q;
int num[MAX * 5];
bool vst[MAX * 5], trig = true;
vector<int> vec[MAX * 5];
struct str {
  int val, idx;
  bool operator<(const str& A) const { return val < A.val; }
};
str arr[MAX * 5];
struct str2 {
  int val, nxt;
  bool operator<(const str2& A) const { return val < A.val; }
};
vector<str2> nvec[MAX * 5];
void dfs(int cur) {
  vst[cur] = true;
  int cnt = 0;
  for (str2 nxt : nvec[cur]) {
    if (!vst[nxt.nxt]) {
      dfs(nxt.nxt);
    }
    if (nxt.val == num[cur]) trig = false;
    if (cnt == nxt.val - 1) cnt++;
  }
  if (cnt < num[cur] - 1) trig = false;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    vec[a].push_back(b);
    vec[b].push_back(a);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &num[i]);
    arr[i] = {num[i], i};
  }
  for (int i = 1; i <= n; ++i) {
    for (int node : vec[i]) {
      nvec[i].push_back({num[node], node});
    }
    sort(nvec[i].begin(), nvec[i].end());
  }
  for (int i = 1; i <= n && trig; ++i) {
    if (!vst[i]) dfs(i);
  }
  if (!trig) {
    printf("-1");
    return 0;
  }
  sort(arr + 1, arr + n + 1);
  for (int i = 1; i <= n; ++i) {
    printf("%d ", arr[i].idx);
  }
}
