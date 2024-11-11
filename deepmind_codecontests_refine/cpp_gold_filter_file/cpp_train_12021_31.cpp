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
int arr[1010], brr[1010];
struct EDGE {
  int v;
  double f, p;
  double weight;
} tedge;
vector<EDGE> adj[1010];
int inq[1010], par[1010];
double vis[1010];
double SPFA(int limit) {
  int res = 0, i, j, k, fl = 0;
  for (i = 0; i <= limit; i++) vis[i] = inf * inf;
  vis[0] = 0;
  deque<int> dq;
  dq.push_back(0);
  while (!dq.empty()) {
    int s = dq.front();
    dq.pop_front();
    inq[s] = 0;
    for (i = 0; i < adj[s].size(); i++) {
      int t = adj[s][i].v;
      if (vis[s] + adj[s][i].weight < vis[t]) {
        vis[t] = vis[s] + adj[s][i].weight;
        par[t] = s;
        if (inq[t] == 0) {
          inq[t] = 1;
          dq.push_back(t);
        }
      }
    }
  }
  return vis[limit];
}
int spFlag = 0;
vector<int> answer;
void recordRes(int s) {
  if (s == 0) {
    answer.clear();
    return;
  }
  recordRes(par[s]);
  answer.push_back(s);
}
int main() {
  int n, l;
  scanf("%d %d", &n, &l);
  for (int i = (1); i <= (n); ++i) {
    scanf("%d %d", &arr[i], &brr[i]);
  }
  for (int i = (0); i <= (n - 1); ++i) {
    for (int j = (i + 1); j <= (n); ++j) {
      int u = arr[i], v = arr[j];
      double r = v - u;
      tedge.v = j;
      tedge.f = sqrt(((r - l) + eps < 0 ? -(r - l) : (r - l)));
      tedge.p = brr[j];
      adj[i].push_back(tedge);
    }
  }
  double low = 0, high = 1000000000;
  while (((high - low) + eps < 0 ? -(high - low) : (high - low)) > eps) {
    double x = (high + low) / 2;
    for (int i = (0); i <= (n); ++i) {
      for (int j = (0); j <= (((int)(adj[i]).size()) - 1); ++j) {
        adj[i][j].weight = adj[i][j].f - x * adj[i][j].p;
      }
    }
    double r = SPFA(n);
    if (r + eps < 0)
      high = x;
    else if (r > 0 + eps)
      low = x;
    else {
      break;
    }
  }
  recordRes(n);
  for (int i = (0); i <= (((int)(answer).size()) - 1); ++i) {
    if (i) printf(" ");
    printf("%d", answer[i]);
  }
  puts("");
  return 0;
}
