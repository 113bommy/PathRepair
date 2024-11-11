#include <bits/stdc++.h>
const int mo = 1000000007;
const int inf = 0x3f3f3f3f;
double pi = 3.14159265358979323846;
double e = 2.71828182845904523536;
using namespace std;
void read(int &x) {
  int f = 1;
  x = 0;
  char ch = getchar();
  while (ch < '0' && ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
}
struct node {
  int x, y, z;
} cnm[100005];
vector<int> v[100005];
int top[100005];
int in[100005];
int n, m;
bool check(int mid) {
  queue<int> q;
  int cnt = 1;
  for (int i = 1; i <= n; i++) v[i].clear();
  memset(in, 0, sizeof(in));
  for (int i = 1; i <= m; i++) {
    if (cnm[i].z > mid) {
      v[cnm[i].x].push_back(cnm[i].y);
      in[cnm[i].y]++;
    }
  }
  for (int i = 1; i <= n; i++)
    if (in[i] == 0) q.push(i), top[i] = cnt++;
  while (!q.empty()) {
    int t = q.front();
    q.pop();
    for (int i = 0; i < v[t].size(); i++) {
      in[v[t][i]]--;
      if (in[v[t][i]] == 0) top[v[t][i]] = cnt++, q.push(v[t][i]);
    }
  }
  for (int i = 1; i <= n; i++)
    if (in[i]) return 0;
  return 1;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) cin >> cnm[i].x >> cnm[i].y >> cnm[i].z;
  int l = 1, r = inf, mid;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (check(mid))
      r = mid - 1;
    else
      l = mid + 1;
  }
  if (check(r))
    mid = r;
  else
    mid = l, check(l);
  vector<int> ans;
  for (int i = 1; i <= m; i++)
    if (cnm[i].z <= mid && top[cnm[i].x] > top[cnm[i].y]) ans.push_back(i);
  cout << mid << ' ' << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
  cout << endl;
  return 0;
}
