#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  char str[n][m + 1];
  for (int i = 0; i < n; i++) cin >> str[i];
  int freq[m];
  memset(freq, 0, sizeof(freq));
  for (int i = 0; i < m; i++) {
    int a[26], ans = -1;
    memset(a, 0, sizeof(a));
    for (int j = 0; j < n; j++) {
      a[str[j][i] - 97]++;
      if (a[str[j][i] - 97] > ans) ans = a[str[j][i] - 97];
    }
    freq[i] = ans;
  }
  int b, ans = 0;
  for (int i = 0; i < m; i++) {
    cin >> b;
    ans += b * freq[i];
  }
  cout << ans << endl;
}
