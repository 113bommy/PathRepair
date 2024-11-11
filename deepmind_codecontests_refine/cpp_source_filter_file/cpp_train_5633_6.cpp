#include <bits/stdc++.h>
using namespace std;
template <class T>
using vec = vector<T>;
const long long inf = pow(2, 62);
const long long mod = 1e9 + 7;
long long dx[8] = {1, 0, -1, 0, -1, 1, -1, 1};
long long dy[8] = {0, 1, 0, -1, -1, -1, 1, 1};
long long input() {
  long long tmp;
  cin >> tmp;
  return tmp;
}
string raw_input() {
  string tmp;
  cin >> tmp;
  return tmp;
}
string readline() {
  string s;
  getline(cin, s);
  return s;
}
template <class T>
void printx(T n) {
  cout << n;
}
template <class T, class U>
void printx(pair<T, U> p) {
  cout << "(" << p.first << "," << p.second << ")";
}
template <class T>
void printx(vector<T> v) {
  cout << "{";
  for (long long i = 0; i < v.size(); i++) {
    printx(v[i]);
    if (i != v.size() - 1) printx(",");
  }
  cout << "}";
}
template <class T>
void print(T n) {
  printx(n);
  cout << endl;
}
template <class T>
void print(set<T> s) {
  cout << "{";
  for (auto(e) = s.begin(); (e) != s.end(); (e)++) {
    if (e != s.begin()) printx(",");
    printx(*e);
  }
  cout << "}" << endl;
}
template <class T, class U>
void print(map<T, U> mp) {
  cout << "{";
  for (auto(e) = mp.begin(); (e) != mp.end(); (e)++) {
    cout << "(" << e->first << "," << e->second << ")";
  }
  cout << "}" << endl;
}
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
string a;
long long dp[18][18][2];
long long dfs(long long i, long long cnt, bool m) {
  if (dp[i][cnt][m] > -1) return dp[i][cnt][m];
  if (i == a.size()) {
    if (cnt <= 3)
      return 1;
    else
      return 0;
  }
  long long nxt = a[i] - '0';
  long long ans = 0;
  for (long long j = 0; j <= (m ? nxt : 9); j++) {
    ans += dfs(i + 1, cnt + (j > 0 ? 1 : 0), (m && (j == nxt) ? true : false));
  }
  return dp[i][cnt][m] = ans;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  long long n = input();
  for (long long i = 0; i < n; i++) {
    long long t = input();
    t--;
    a = to_string(t);
    memset(dp, -1, sizeof(dp));
    long long l = dfs(0, 0, true);
    memset(dp, -1, sizeof(dp));
    a = raw_input();
    long long r = dfs(0, 0, true);
    print(r - l);
  }
}
