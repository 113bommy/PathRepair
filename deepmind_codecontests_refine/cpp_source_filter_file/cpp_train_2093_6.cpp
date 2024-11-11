#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;
template <typename T>
void print(T &v) {
  for (auto i : v) {
    cout << i << ' ';
  }
  cout << '\n';
}
void solve() {
  int n;
  cin >> n;
  string a;
  cin >> a;
  for (int i = 1; i <= 900; ++i) {
    int cnt = 0;
    int otr = 0;
    for (int j = 0; j < a.size(); ++j) {
      if (cnt + (a[j] - '0') > i) {
        otr = 0;
        break;
      } else if (cnt + (a[j] - '0') == i) {
        otr++;
        cnt = 0;
      } else {
        cnt += (a[j] - '0');
      }
    }
    if (otr >= 2 && cnt == 0) {
      cout << "YES";
      return;
    }
  }
  cout << "NO";
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long t = 1;
  while (t--) solve();
}
