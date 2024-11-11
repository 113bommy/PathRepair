#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool MX(T &l, const T &r) {
  return l < r ? l = r, 1 : 0;
}
template <class T>
inline bool MN(T &l, const T &r) {
  return l > r ? l = r, 1 : 0;
}
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;
const int MOD = (int)1e9 + 7;
const int MAXN = (int)2e5 + 5;
bool cmp(int x, int y) { return x > y; }
int main() {
  int n, cnt = 0;
  cin >> n;
  vector<int> a, b, c;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    string s;
    int x;
    cin >> s >> x;
    if (s == "11")
      ++cnt, ans += x;
    else if (s == "01")
      a.push_back(x);
    else if (s == "10")
      b.push_back(x);
    else if (s == "00")
      c.push_back(x);
  }
  sort(a.begin(), a.end(), cmp);
  sort(b.begin(), b.end(), cmp);
  int sz = min(((int)a.size()), ((int)b.size()));
  for (int i = 0; i < sz; i++) {
    ans += a[i] + b[i];
  }
  for (int i = 0; i < ((int)a.size()); ++i) c.push_back(a[i]);
  for (int i = 0; i < ((int)b.size()); ++i) c.push_back(b[i]);
  sort(c.begin(), c.end(), cmp);
  for (int i = 0; i < cnt && i < ((int)c.size()); ++i) {
    ans += c[i];
  }
  cout << ans << endl;
  return 0;
}
