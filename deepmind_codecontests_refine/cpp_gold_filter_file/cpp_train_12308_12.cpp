#include <bits/stdc++.h>
using namespace std;
int dir1[6][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, 1}};
int dir2[6][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, -1}, {-1, -1}};
const long long INF = 0x7f7f7f7f7f7f7f7f;
const int inf = 0x3f3f3f3f;
const double pi = 3.14159265358979;
const int mod = 100007;
const int N = 200005;
inline long long read() {
  long long x = 0;
  bool f = true;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = false;
    c = getchar();
  }
  while (c >= '0' && c <= '9')
    x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  return f ? x : -x;
}
long long gcd(long long m, long long n) { return n == 0 ? m : gcd(n, m % n); }
struct node {
  int x, y;
};
node a[N];
int n;
bool cmp(node x, node y) { return x.x < y.x; }
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) a[i].x = read();
  for (int i = 1; i <= n; i++) a[i].y = read();
  sort(a + 1, a + n + 1, cmp);
  priority_queue<int> q;
  long long cur = 1, cnt = 0, ans = 0, tmp = 0;
  while (!q.empty() || cur < n) {
    cnt++;
    if (q.empty()) {
      cnt = a[cur].x;
      while (cur <= n && cnt == a[cur].x) {
        tmp += a[cur].y;
        q.push(a[cur].y);
        cur++;
      }
    } else {
      while (cnt == a[cur].x && cur <= n) {
        tmp += a[cur].y;
        q.push(a[cur].y);
        cur++;
      }
    }
    tmp -= q.top();
    q.pop();
    ans += tmp;
  }
  cout << ans << endl;
  return 0;
}
