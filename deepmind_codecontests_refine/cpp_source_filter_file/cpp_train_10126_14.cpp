#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  bool flag = true;
  char word[n][1001];
  for (int i = 0; i < n; i++) cin >> word[i];
  int a[26];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < strlen(word[i]); j++) a[word[i][j] - 'a']++;
  }
  for (int i = 0; i < n; i++) {
    if (a[i] % n != 0) {
      cout << "NO"
           << "\n";
      flag = false;
      break;
    }
  }
  if (flag == true)
    cout << "YES"
         << "\n";
}
int main(void) {
  std::ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}
