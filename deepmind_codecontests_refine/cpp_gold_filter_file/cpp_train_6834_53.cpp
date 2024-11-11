#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int a[N], b[N];
int main() {
  string ans = "";
  int k;
  cin >> k;
  if (k & 1) ans += '4', k--;
  while (ans.size() < 19 && k) {
    k -= 2;
    ans += '8';
  }
  if (ans.size() >= 19) return puts("-1"), 0;
  cout << ans << endl;
}
