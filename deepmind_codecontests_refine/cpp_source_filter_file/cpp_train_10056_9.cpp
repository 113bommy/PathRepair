#include <bits/stdc++.h>
using namespace std;
const long long inf = (long long)1e18;
const long long mod = (long long)1e9 + 7;
const double pi = acos(-1.0);
const double eps = (double)1e-9;
const int dx[] = {0, 0, 1, 0, -1};
const int dy[] = {0, 1, 0, -1, 0};
const int N = 100500;
vector<int> ans;
int n, a[45], b[45];
inline bool check(int x) {
  int c[45], d[45], end[45];
  memset(end, 0, sizeof(end));
  for (int i = 0; i <= 39; i++) {
    c[i] = a[i];
    d[i] = b[i];
  }
  int mn = min(c[0], x);
  if (mn < x) return 0;
  int pr = mn;
  for (int i = 0; i <= 39; i++) {
    mn = min(mn, c[i]);
    end[i] = pr - mn;
    c[i] -= mn;
    pr = mn;
  }
  int cur = 0;
  for (int i = 0; i <= 39; i++) {
    cur += c[i] + d[i];
    mn = min(cur, end[i]);
    cur -= mn;
    end[i] -= mn;
  }
  return cur == 0;
}
int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    long long y = 1;
    int pw = 0;
    while (y < x) y <<= 1, pw++;
    if (x == y)
      a[pw]++;
    else
      b[pw]++;
  }
  for (int i = 1; i <= n; i++)
    if (check(i)) ans.push_back(i);
  if (ans.empty()) ans.push_back(-1);
  for (auto i : ans) cout << i << " ";
  return 0;
}
