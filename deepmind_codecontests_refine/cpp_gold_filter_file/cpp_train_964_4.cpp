#include <bits/stdc++.h>
using namespace std;
const int MAX = numeric_limits<int>::max();
const int MIN = numeric_limits<int>::min();
const long long mod = 1e9 + 7;
const int N = 100010;
void FastRead() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
inline char Nowchar() {
  static char buf[1 << 20], *p1 = buf, *p2 = buf;
  bool flag =
      (p1 == p2) && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2);
  return flag ? EOF : *p1++;
}
inline int Read() {
  int x = 0, f = 1;
  static char c = Nowchar();
  for (; c > '9' || c < '0'; c = Nowchar()) {
    if (c == '-') f = -1;
  }
  for (; c <= '9' && c >= '0'; c = Nowchar()) {
    x = (x << 3) + (x << 1) + c - 48;
  }
  return x * f;
}
void Test() { return; }
void Solve() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a;
    string s;
    cin >> s;
    int lwp = -2;
    int ans = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'W') {
        if (lwp != i - 1 && lwp >= 0) {
          a.push_back(i - lwp - 1);
        }
        ans += (lwp == i - 1) + 1;
        lwp = i;
        cnt++;
      }
    }
    k = min(n - cnt, k);
    ans += 2 * k;
    if (lwp < 0) {
      if (k > 0) {
        ans--;
      }
    } else {
      sort(a.begin(), a.end());
      for (auto x : a) {
        if (k >= x) {
          ans++;
          k -= x;
        }
      }
    }
    cout << ans << endl;
  }
}
int main(int argc, char** argv) {
  Solve();
  return 0;
}
