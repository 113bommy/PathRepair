#include <bits/stdc++.h>
using namespace std;
struct _ {
  _() { ios_base::sync_with_stdio(0); }
} _;
template <class A, class B>
ostream &operator<<(ostream &o, pair<A, B> t) {
  o << "(" << t.first << ", " << t.second << ")";
  return o;
}
template <class T>
string tostring(T first, int len = 0, char c = '0') {
  stringstream ss;
  ss << first;
  string r = ss.str();
  if (r.length() < len) r = string(len - r.length(), c) + r;
  return r;
}
template <class T>
void PV(T a, T b, int n = 0, int w = 0, string s = " ") {
  int c = 0;
  while (a != b) {
    cout << tostring(*a++, w, ' ');
    if (a != b && (n == 0 || ++c % n))
      cout << s;
    else
      cout << endl;
  }
}
template <class T>
inline bool chmin(T &a, T b) {
  return a > b ? a = b, 1 : 0;
}
template <class T>
inline bool chmax(T &a, T b) {
  return a < b ? a = b, 1 : 0;
}
const long long linf = 0x3f3f3f3f3f3f3f3fLL;
const int inf = 0x3f3f3f3f;
const int mod = int(1e9) + 7;
const int N = 111111;
int first, second, n, d;
int OK[444][444];
int a[22];
int b[22];
bool dp[444][444];
int dist(int i, int j) {
  i -= 222;
  j -= 222;
  return i * i + j * j;
}
int main() {
  cin >> first >> second >> n >> d;
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
  vector<pair<int, int> > toporder;
  for (int i = 0; i < 444; i++)
    for (int j = 0; j < 444; j++) toporder.push_back(make_pair(i + j, j));
  sort((toporder).begin(), (toporder).end());
  reverse((toporder).begin(), (toporder).end());
  first += 222, second += 222;
  for (auto i : toporder) {
    int tx = i.first - i.second;
    int ty = i.second;
    if (dist(tx, ty) > d * d) continue;
    for (int j = 0; j < n; j++) {
      int nx = a[j] + tx;
      int ny = b[j] + ty;
      if (dist(nx, ny) <= d * d && !dp[nx][ny]) dp[tx][ty] = 1;
    }
  }
  cout << (dp[first][second] ? "Anton" : "Dasha") << endl;
  return 0;
}
