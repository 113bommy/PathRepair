#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int n = s.size();
  int smol[n + 1];
  int big[n + 1];
  smol[0] = 0;
  big[n] = 0;
  for (int i = 1; i <= n; i++) {
    smol[i] = smol[i - 1];
    if (s[i - 1] >= 'a' && s[i - 1] <= 'z') smol[i]++;
  }
  for (int i = n - 1; i >= 0; i--) {
    big[i] = big[i + 1];
    if (s[i] >= 'A' && s[i] <= 'Z') big[i]++;
  }
  int ans = n;
  for (int i = 1; i <= n; i++) ans = min(ans, smol[i] + big[i]);
  cout << ans << endl;
}
