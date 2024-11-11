#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.141592;
const long long int dx4[4] = {0, 1, 0, -1};
const long long int dy4[4] = {-1, 0, 1, 0};
const long long int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const long long int dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
vector<string> vec_splitter(string s) {
  for (char& c : s) c = c == ',' ? ' ' : c;
  stringstream ss;
  ss << s;
  vector<string> res;
  for (string z; ss >> z; res.push_back(z))
    ;
  return res;
}
void debug_out(vector<string> __attribute__((unused)) args,
               __attribute__((unused)) long long int idx) {
  cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(vector<string> args, long long int idx, Head H, Tail... T) {
  if (idx > 0) cerr << ", ";
  stringstream ss;
  ss << H;
  cerr << args[idx] << " = " << ss.str();
  debug_out(args, idx + 1, T...);
}
long long int first[105], second[105];
long long int x = 0, y = 0;
bool check(long long int dx, long long int dy) {
  if (!x and y) {
    return (!dx and dy / y >= 0 and dy % y == 0);
  }
  if (!y and x) {
    return (!dy and dx / x >= 0 and dx % x == 0);
  }
  if (!x and !y) {
    return (!dx and !dy);
  }
  if (x and y) {
    return (dx == dy / y * x and dy % y == 0 and dy / y >= 0);
  }
}
void solve() {
  long long int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  if (!n and !m) {
    cout << "Yes\n";
    return;
  }
  for (long long int i = 0; i < (long long int)s.size(); ++i) {
    if (s[i] == 'U') {
      x += 1;
    } else if (s[i] == 'D') {
      x -= 1;
    } else if (s[i] == 'R') {
      y += 1;
    } else {
      y -= 1;
    }
    first[i] = x, second[i] = y;
  }
  for (long long int i = 0; i < (long long int)s.size(); ++i) {
    if (check(n - first[i], m - second[i])) {
      cout << "Yes\n";
      return;
    }
  }
  cout << "No\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long int T = 1;
  for (long long int i = 1; i <= T; ++i) {
    solve();
  }
  return 0;
}
