#include <bits/stdc++.h>
using namespace std;
const long long inf = 2147383647;
const double pi = 2 * acos(0.0);
const double eps = 1e-9;
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
inline long long gcd(long long a, long long b) {
  a = ((a) < 0 ? -(a) : (a));
  b = ((b) < 0 ? -(b) : (b));
  while (b) {
    a = a % b;
    swap(a, b);
  }
  return a;
}
int ext_gcd(int a, int b, int& x, int& y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  int x1, y1;
  int d = ext_gcd(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
inline long long modInv(int a, int m) {
  int x, y;
  ext_gcd(a, m, x, y);
  if (x < 0) x += m;
  return x;
}
inline long long power(long long a, long long p) {
  long long res = 1, x = a;
  while (p) {
    if (p & 1) res = (res * x);
    x = (x * x);
    p >>= 1;
  }
  return res;
}
inline long long bigmod(long long a, long long p, long long m) {
  long long res = 1, x = a % m;
  while (p) {
    if (p & 1) res = (res * x) % m;
    x = (x * x) % m;
    p >>= 1;
  }
  return res;
}
map<string, int> mp;
char buf1[3], buf2[3], str[10];
int ind;
vector<int> adj[500000];
vector<string> rmap;
int deg[500000];
int estart[500000];
vector<int> path;
int cnt = 0;
void dfs(int s) {
  for (; estart[s] < adj[s].size();) {
    int t = adj[s][estart[s]];
    estart[s]++;
    dfs(t);
  }
  cnt++;
  path.push_back(s);
}
int main() {
  int n;
  scanf("%d", &n);
  buf1[2] = buf2[2] = 0;
  for (int i = (0); i <= (n - 1); ++i) {
    scanf("%s", str);
    buf1[0] = str[0];
    buf1[1] = str[1];
    buf2[0] = str[1];
    buf2[1] = str[2];
    if (mp.find(buf1) == mp.end()) {
      mp[buf1] = ind++;
      rmap.push_back(buf1);
    }
    if (mp.find(buf2) == mp.end()) {
      mp[buf2] = ind++;
      rmap.push_back(buf2);
    }
    int u = mp[buf1], v = mp[buf2];
    adj[u].push_back(v);
    deg[u]++;
    deg[v]--;
  }
  bool pos = true;
  int one = 0, mone = 0;
  int start = 0;
  for (int i = (0); i <= (ind - 1); ++i) {
    if (deg[i] == 0) continue;
    if (deg[i] == 1) {
      start = i;
      one++;
    } else if (deg[i] == -1)
      mone++;
    else {
      pos = false;
    }
  }
  if (one > 1 || mone > 1) {
    pos = false;
  }
  if (one + mone == 1) {
    pos = false;
  }
  if (pos == false) {
    printf("NO\n");
    return 0;
  }
  dfs(start);
  if (cnt != n + 1) {
    printf("NO\n");
    return 0;
  }
  reverse((path).begin(), (path).end());
  printf("YES\n");
  for (int i = (0); i <= (((int)(path).size()) - 2); ++i) {
    int u = path[i];
    printf("%c", rmap[u][0]);
  }
  int x = path[((int)(path).size()) - 1];
  printf("%s\n", rmap[x].c_str());
  return 0;
}
