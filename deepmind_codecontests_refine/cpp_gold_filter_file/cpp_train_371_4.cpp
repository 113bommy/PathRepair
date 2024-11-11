#include <bits/stdc++.h>
using namespace std;
int ans[26][2000];
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  char s[3000];
  cin >> s;
  for (int i = 'a'; i <= 'z'; i++) {
    for (int ii = 0; ii <= n - 1; ii++) {
      int mtemp = 0;
      int anstemp = 0;
      for (int j = ii; j <= n - 1; j++) {
        if (s[j] == i) {
          anstemp++;
        } else if (s[j] != i) {
          mtemp++;
          anstemp++;
        }
        if (anstemp > ans[i - 'a'][mtemp]) {
          ans[i - 'a'][mtemp] = anstemp;
        }
      }
    }
    for (int ii = 1; ii <= n; ii++) {
      if (ans[i - 'a'][ii] == 0) {
        ans[i - 'a'][ii] = ans[i - 'a'][ii - 1];
      }
    }
  }
  int q;
  cin >> q;
  for (int ii = 0; ii <= q - 1; ii++) {
    int m;
    char c;
    cin >> m;
    cin >> c;
    cout << ans[c - 'a'][m] << endl;
  }
  return 0;
}
