#include <bits/stdc++.h>
double const EPS = 3e-8;
using namespace std;
template <class T>
T gcd(T a, T b) {
  return (b != 0 ? gcd<T>(b, a % b) : a);
}
template <class T>
T lcm(T a, T b) {
  return (a / gcd<T>(a, b) * b);
}
template <class T>
inline T bigmod(T p, T e, T M) {
  if (e == 0) return 1;
  if (e % 2 == 0) {
    long long t = bigmod(p, e / 2, M);
    return (T)((t * t) % M);
  }
  return (T)((long long)bigmod(p, e - 1, M) * (long long)p) % M;
}
template <class T>
inline T modinverse(T a, T M) {
  return bigmod(a, M - 2, M);
}
template <class T>
inline bool read(T &x) {
  int c = getchar();
  int sgn = 1;
  while (~c && c < '0' || c > '9') {
    if (c == '-') sgn = -1;
    c = getchar();
  }
  for (x = 0; ~c && '0' <= c && c <= '9'; c = getchar()) x = x * 10 + c - '0';
  x *= sgn;
  return ~c;
}
const int maxn = 1000005;
string str;
int inp[1000005], n, Left[maxn], Right[maxn];
struct node {
  int x, y, d;
  node(int x, int y, int d) : x(x), y(y), d(d) {}
};
bool operator<(const node &A, const node &B) {
  if (A.d == B.d) {
    if (A.x == B.x) return A.y > B.y;
    return A.x > B.x;
  }
  return A.d > B.d;
}
priority_queue<node> pq;
bool Vis[maxn];
int main() {
  cin >> n >> str;
  int i;
  for (i = 0; i < n; i++) cin >> inp[i], Left[i] = i - 1, Right[i] = i + 1;
  for (i = 0; i < n - 1; i++) {
    if (str[i] != str[i + 1]) pq.push(node(i, i + 1, abs(inp[i] - inp[i + 1])));
  }
  vector<pair<int, int> > ans;
  while (!pq.empty()) {
    int x, y;
    x = pq.top().x;
    y = pq.top().y;
    pq.pop();
    if (Vis[x] || Vis[y]) continue;
    Vis[x] = 1;
    Vis[y] = 1;
    ans.push_back(make_pair(x, y));
    int nx = Left[x];
    int ny = Right[y];
    Left[ny] = nx;
    Right[nx] = ny;
    if (nx >= 0 && ny < n && str[nx] != str[ny]) {
      pq.push(node(nx, ny, abs(inp[nx] - inp[ny])));
    }
  }
  cout << ans.size() << endl;
  for (i = 0; i < ans.size(); i++) {
    cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
  }
  return 0;
}
