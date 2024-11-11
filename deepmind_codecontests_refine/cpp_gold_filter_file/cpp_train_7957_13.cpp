#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[10000];
  long long int k, w[26];
  cin >> s >> k;
  long long int max = 0;
  for (int i = 0; i < 26; i++) {
    cin >> w[i];
    if (w[i] > max) max = w[i];
  }
  long long int ans = 0;
  for (int i = 0; i < strlen(s); i++) ans += w[s[i] - 'a'] * (i + 1);
  for (int i = strlen(s); i < k + strlen(s); i++) ans += max * (i + 1);
  cout << ans << endl;
}
