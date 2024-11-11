#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  long long ans = 0;
  int r = n;
  for (int i = n - 1; i >= 0; i--) {
    for (int k = 1; i + 2 * k < r; k++)
      if (s[i] == s[i + k] && s[i] == s[i + 2 * k]) {
        r = i + 2 * k;
        break;
      }
    ans += n - r;
  }
  cout << ans << endl;
  return 0;
}
