#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (a == 0)
    return b;
  else
    return gcd(b % a, a);
}
unsigned long long pw(unsigned long long a, unsigned long long b) {
  unsigned long long ans = 1;
  while (b) {
    while (!(b & 1)) b >>= 1, a = (a * a) % 1000000007LL;
    ans = (ans * a) % 1000000007LL, --b;
  }
  return ans;
}
template <typename T>
static T mod(T a, T m) {
  a %= m;
  if (a < 0) a += m;
  return a;
}
template <typename T>
static T inverse(T a, T m) {
  a = mod(a, m);
  if (a == 1) return a;
  return mod((1 - inverse(m, a) * m) / a, m);
}
const int MX = 160;
bool grid[320][320];
bool seen[320][320][31][9];
int dr[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dc[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int t[32];
int n;
unsigned long long a[200005], b[200005];
int x[200005];
vector<pair<int, int> > v;
void func(int r, int c, int st, int dir) {
  if (seen[r][c][st][dir])
    return;
  else
    seen[r][c][st][dir] = true;
  grid[r][c] = true;
  for (int i = 1; i < t[st]; i++) {
    r += dr[dir];
    c += dc[dir];
    grid[r][c] = true;
  }
  if (st < n - 1) {
    int d1 = (dir + 1) % 8;
    int d2 = (dir + 7) % 8;
    int r1 = r + dr[d1];
    int c1 = c + dc[d1];
    int r2 = r + dr[d2];
    int c2 = c + dc[d2];
    func(r1, c1, st + 1, d1);
    func(r2, c2, st + 1, d2);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  unsigned long long t;
  cin >> t;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  int cnt = 0;
  for (int i = 1; i <= n;) {
    if (x[i] > i) {
      int j = i + 1;
      while (j <= x[i]) {
        if (x[j] > x[i] || x[j] < j || x[j] < x[i]) {
          cout << "No" << endl;
          return 0;
        }
        j++;
      }
      v.push_back(make_pair(i, x[i]));
      i = x[i] + 1;
    } else if (x[i] < i) {
      cout << "No" << endl;
      return 0;
    } else
      i++;
  }
  int sz = v.size();
  int j = 0;
  int ga = 0;
  for (int i = 1; i <= n;) {
    if (sz > 0 && i == v[j].first) {
      int fi = v[j].first;
      int se = v[j].second;
      for (int k = fi; k < se; k++) {
        b[k] = max(a[k + 1] + t, b[k - 1] + 1);
      }
      b[se] = max(a[se] + t, b[se - 1] + 1);
      if (se <= n - 1 && b[se] >= a[se + 1] + t) {
        cout << "No" << endl;
        return 0;
      }
      i = v[j].second + 1;
      j++;
    } else {
      b[i] = max(a[i] + t, b[i - 1] + 1);
      i++;
    }
  }
  cout << "Yes" << endl;
  for (int i = 1; i <= n; i++) {
    cout << b[i] << " ";
  }
  cout << endl;
  return 0;
}
