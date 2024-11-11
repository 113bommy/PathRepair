#include <bits/stdc++.h>
using namespace std;
int t, i, k, n, j, minim;
char s[5001], mini[5001], o[5001], rev[5001];
int main() {
  cin >> t;
  while (t--) {
    fill(mini, mini + 5001, 'z');
    fill(o, o + 5001, 0);
    cin >> n >> s;
    for (i = 1; i <= n; i++) {
      strcpy(o, s + i - 1);
      if (i % 2 != n % 2) {
        for (int j = 0; j < i - 1; j++) rev[j] = s[j];
      } else {
        for (int j = 0; j < i - 1; j++) rev[j] = s[i - 2 - j];
      }
      strcpy(o + n - i + 1, rev);
      if (strcmp(mini, o) > 0) {
        strcpy(mini, o);
        minim = i;
      }
      fill(rev, rev + i + 1, 0);
    }
    cout << mini << endl << minim << endl;
  }
}
