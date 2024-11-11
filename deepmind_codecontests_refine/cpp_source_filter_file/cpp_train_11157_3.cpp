#include <bits/stdc++.h>
using namespace std;
int n, k;
string s;
int sol(string a) {
  int co = 0;
  for (int i = 0; i < k; i++)
    if (s[i] != a[i % 3]) co++;
  int ans = co;
  for (int i = 1; i < n - k; i++) {
    if (s[i - 1] != a[(i - 1) % 3]) co--;
    if (s[i + k - 1] != a[(i + k - 1) % 3]) co++;
    ans = min(ans, co);
  }
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k >> s;
    cout << min(min(sol("RGB"), sol("GBR")), sol("BRG")) << endl;
  }
}
