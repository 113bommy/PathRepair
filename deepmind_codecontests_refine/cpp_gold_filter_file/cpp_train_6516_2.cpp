#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, idx = 0;
  string ans = "", aux = "bbaabbaabbaa";
  cin >> n;
  while (n--) {
    ans += aux[idx];
    idx++;
    if (idx == aux.size()) idx = 0;
  }
  cout << ans << "\n";
}
