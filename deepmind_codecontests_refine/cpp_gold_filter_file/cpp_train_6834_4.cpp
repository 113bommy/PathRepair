#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1e5 + 1;
inline void files() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}
long long n, m, c;
int main() {
  files();
  cin >> n;
  long long num = 0;
  string ans;
  while (num + 1 < n) {
    ans += "8";
    num += 2;
  }
  if (num == n - 1) ans += "9";
  if (ans.size() < 19)
    cout << ans;
  else
    cout << -1;
}
