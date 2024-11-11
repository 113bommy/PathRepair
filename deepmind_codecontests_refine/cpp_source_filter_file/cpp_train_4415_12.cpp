#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int res = 0;
  int neg;
  while (true) {
    char ch = getchar();
    if (ch >= '0' && ch <= '9' || ch == '-') {
      if (ch == '-')
        neg = -1;
      else
        neg = 1, res = ch - '0';
      break;
    }
  }
  while (true) {
    char ch = getchar();
    if (ch >= '0' && ch <= '9')
      res *= 10, res += ch - '0';
    else
      break;
  }
  return res * neg;
}
const int maxn = 300020;
const int maxm = 1000020;
const int mo = 314000000;
int a, b;
int used[maxn], id[maxn];
long long dnmin[maxn], dnmax[maxn];
long long ar[maxn], val[maxn], val2[maxn];
int dns[maxn], sz[maxn];
vector<int> w[maxn], q[maxn], rev[maxn];
long long fmin(int n) {
  long long &ret = dnmin[n];
  if (used[n]) {
    if (used[n] == 2) return ret;
    return -1;
  }
  used[n] = 1;
  ret = -1;
  for (int i = 0; i < q[n].size(); i++) {
    int t = q[n][i], v = 0;
    long long h = 0;
    for (int j = 0; j < w[t].size(); j++) {
      if (w[t][j] == -1) {
        if (h != -1) h++;
        continue;
      }
      long long h2 = fmin(w[t][j]);
      if (h2 == -1) h = -1;
      if (h != -1) h += h2;
    }
    if (h > mo) h = mo;
    if (h == -1) continue;
    if (ret == -1)
      ret = h;
    else
      ret = min(ret, (h));
  }
  used[n] = 2;
  return ret;
}
long long fmax(int n) {
  long long &ret = dnmax[n];
  if (used[n]) {
    if (used[n] == 2) return ret;
    return -1;
  }
  used[n] = 1;
  assert(ar[n] != -1);
  ret = ar[n];
  for (int i = 0; i < q[n].size(); i++) {
    int t = q[n][i], v = 0;
    long long h = val2[t];
    int c = 0;
    for (int j = 0; j < w[t].size(); j++) {
      if (ar[w[t][j]] == -1) {
        c = 1;
        break;
      }
      long long h2 = fmax(w[t][j]);
      if (h2 == -1) h = -1;
      if (h != -1) h += h2;
    }
    if (c) continue;
    if (h > mo) h = mo;
    if (h == -1) ret = -1;
    if (ret != -1) ret = max(ret, (h));
  }
  used[n] = 2;
  return ret;
}
int main() {
  scanf("%d %d", &b, &a);
  for (int i = 1, k; i <= b; i++) {
    scanf("%d %d", &id[i], &k);
    q[id[i]].push_back(i);
    for (int j = 0, v; j < k; j++) {
      scanf("%d", &v);
      if (v == -1) {
        val[i]++;
        continue;
      }
      sz[i]++;
      rev[v].push_back(i);
      w[i].push_back(v);
    }
  }
  memset(ar, -1, sizeof(ar));
  priority_queue<pair<long long, long long> > q;
  for (int i = 1; i <= b; i++) {
    val2[i] = val[i];
    if (!sz[i]) q.push(pair<long long, long long>(-val[i], id[i]));
  }
  while (!q.empty()) {
    pair<long long, long long> t = q.top();
    q.pop();
    int n = t.second;
    int v = -t.first;
    if (used[n]) continue;
    used[n] = 1;
    ar[n] = v;
    for (int i = 0; i < (int)rev[n].size(); i++) {
      val[rev[n][i]] += v;
      if (val[rev[n][i]] > mo) val[rev[n][i]] = mo;
      sz[rev[n][i]]--;
      if (!sz[rev[n][i]])
        q.push(pair<long long, long long>(-val[rev[n][i]], rev[n][i]));
    }
  }
  memset(used, 0, sizeof(used));
  for (int i = 1; i <= a; i++) {
    if (ar[i] == -1)
      printf("-1 -1\n");
    else {
      long long t = fmax(i);
      if (t == -1) t = -2;
      printf("%lld %lld\n", ar[i], t);
    }
  }
  return 0;
}
