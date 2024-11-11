#include <bits/stdc++.h>
using namespace std;
inline int toInt(string s) {
  int v;
  istringstream sin(s);
  sin >> v;
  return v;
}
template <class T>
inline string toString(T x) {
  ostringstream sout;
  sout << x;
  return sout.str();
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
const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
long int gcd(long int a, long int b) { return b ? gcd(b, a % b) : a; }
long int lcm(long int a, long int b) { return a / gcd(a, b) * b; }
void solve_test() {
  long int n, k;
  cin >> n >> k;
  vector<long int> x(n), y(n);
  for (auto &it : x) cin >> it;
  for (auto &it : y) cin >> it;
  sort(x.begin(), x.end());
  vector<long int> l(n), r(n);
  long int j = n - 1;
  for (long int i = n - 1; i >= 0; i--) {
    while (x[j] - x[i] > k) j--;
    r[i] = j - i + 1;
    if (i < n - 1) r[i] = max(r[i], r[i + 1]);
  }
  j = 0;
  for (long int i = 0; i < n; i++) {
    while (x[i] - x[j] > k) j++;
    l[i] = i - j + 1;
    if (i > 0) l[i] = max(l[i], l[i - 1]);
  }
  long int answer = 0;
  for (int i = 0; i < n - 1; i++) {
    answer = max(answer, l[i] + r[i + 1]);
  }
  cout << answer << '\n';
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long int test;
  cin >> test;
  while (test--) {
    solve_test();
  }
  return 0;
}
