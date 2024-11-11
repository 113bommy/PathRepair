#include <bits/stdc++.h>
using namespace std;
int a[109];
int main() {
  int n;
  char s[109];
  cin >> n;
  for (int j = 1; j <= n; j++) {
    cin >> s[j];
  }
  int k, t = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'B') {
      t++;
      while (s[i] == 'B') {
        a[t]++;
        i++;
      }
    }
  }
  cout << t << endl;
  for (int i = 1; i <= t; i++) {
    if (i != t) cout << a[i] << " ";
    if (i == t) cout << a[i] << endl;
  }
  return 0;
}
