#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  cin.sync_with_stdio(0);
  string s;
  cin >> s;
  int n = s.size();
  int ans = 100004;
  for (char a = 'a'; a <= 'z'; a++) {
    int k = 1;
    int ls = -1;
    for (int i = 0; i < n; i++) {
      if (s[i] == a) {
        k = max(k, i - ls);
        ls = i;
      } else
        k = max(k, i + 1 - ls);
    }
    ans = min(ans, k);
  }
  cout << ans << endl;
  return 0;
}
