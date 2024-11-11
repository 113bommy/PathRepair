#include <bits/stdc++.h>
using namespace std;
template <typename T>
using maxHeap = priority_queue<T, vector<T>, less<T>>;
template <typename T>
using minHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename Iter>
ostream& _out(ostream& s, Iter b, Iter e) {
  s << "[";
  for (auto it = b; it != e; it++) s << (it == b ? "" : " ") << *it;
  s << "]";
  return s;
}
template <typename A, typename B>
ostream& operator<<(ostream& s, const pair<A, B>& p) {
  return s << "(" << p.first << "," << p.second << ")";
}
template <typename T>
ostream& operator<<(ostream& s, const vector<T>& c) {
  return _out(s, begin(c), end(c));
}
bool debug = 0;
template <typename T>
void DEBUG(const T& x) {
  if (debug) cerr << x;
}
template <typename T, typename... Args>
void DEBUG(const T& head, const Args&... tail) {
  if (debug) {
    cerr << head;
    DEBUG(tail...);
  }
}
const int N = 5000 + 5;
int sum[N][N], bkt[N];
int main(int argc, char* argv[]) {
  if (argc > 1 and string(argv[1]) == "-D") debug = 1;
  if (!debug) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  }
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    string ss;
    cin >> ss;
    for (int j = 1; j <= m; j++) {
      sum[i][j] = ss[j - 1] - '0';
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (sum[i][j] != 0) sum[i][j] += sum[i][j - 1];
    }
  }
  int ans = 0;
  for (int j = 1; j <= m; j++) {
    memset(bkt, 0, sizeof(bkt));
    for (int i = 1; i <= n; i++) bkt[sum[i][j]]++;
    int num = 0;
    for (int i = n; i >= 1; i--) {
      num += bkt[i];
      ans = max(ans, num * i);
    }
  }
  cout << ans << '\n';
  return 0;
}
