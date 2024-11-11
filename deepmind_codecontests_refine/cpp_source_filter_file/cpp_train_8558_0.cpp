#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const long long INF = -9999999999999;
const int maxn = 200005;
const int maxm = 1000006;
const int ox3f = 1061109567;
const int fox3f = -2139062144;
const long long ox3fll = 4557430888798830399;
int n, m, T;
int fa[maxn], flag[maxn], tim[maxn], nex[100005];
int cntTim, mal, mai, sum;
vector<int> v[maxn];
void spfa1(int x) {
  flag[x] = true;
  queue<int> q;
  q.push(x);
  while (!q.empty()) {
    int z = q.front();
    q.pop();
    for (int i : v[z]) {
      if (!flag[i]) {
        flag[i] = true;
        q.push(i);
        mai = i;
      }
    }
  }
}
void spfa2(int x) {
  memset(flag, 0, sizeof flag);
  mai = 0;
  fa[x] = 0;
  queue<int> q;
  q.push(x);
  flag[x] = true;
  while (!q.empty()) {
    int z = q.front();
    q.pop();
    for (int i : v[z]) {
      if (!flag[i]) {
        tim[i] = tim[z] + 1;
        sum = tim[i];
        fa[i] = z;
        mai = i;
        q.push(i);
        flag[i] = true;
      }
    }
  }
}
void spfa4(int x) {
  queue<int> q;
  q.push(x);
  while (!q.empty()) {
    int z = q.front();
    q.pop();
    for (int i : v[z]) {
      if (flag[i] || i == fa[z]) continue;
      flag[i] = true;
      if (tim[i] - tim[x] > mal) {
        mal = tim[i] - tim[x];
        mai = i;
      }
      q.push(i);
    }
  }
}
void spfa3(int x) {
  memset(flag, 0, sizeof flag);
  while (x != 0) {
    flag[x] = true;
    flag[fa[x]] = true;
    spfa4(x);
    x = fa[x];
  }
}
void solve() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
    nex[x]++;
    nex[y]++;
  }
  for (int i = 1; i <= n; i++)
    if (nex[i] == 1) {
      spfa1(i);
      break;
    }
  int a, b, c;
  a = mai;
  spfa2(a);
  b = mai;
  spfa3(b);
  c = mai;
  if (mal == 0) c = fa[b];
  cout << sum + mal << endl;
  cout << a << " " << b << " " << c << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
