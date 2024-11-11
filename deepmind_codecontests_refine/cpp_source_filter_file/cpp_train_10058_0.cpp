#include <bits/stdc++.h>
using namespace std;
int main() {
  map<string, int> M, T;
  int n, m, a[5];
  string s, s2, s3, s4;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    M[s]++;
    T[s] = 1;
  }
  for (int p = 1; p <= m; p++) {
    int x = 0;
    cin >> s;
    int t = 0, i = 0;
    while (s[i] >= '?' && s[i] <= 'e') {
      if (s[i] == '?') a[++t] = i;
      i++;
    }
    for (int i = 0; i <= 5; i++) {
      s2 = s;
      if (t >= 3) {
        if (i)
          s2[a[3]] = i + 'a' - 1;
        else
          s2.erase(a[3], 1);
      } else
        i = 5;
      for (int j = 0; j <= 5; j++) {
        s3 = s2;
        if (t >= 2) {
          if (j)
            s3[a[2]] = j + 'a' - 1;
          else
            s3.erase(a[2], 1);
        } else
          j = 5;
        for (int k = 0; k <= 5; k++) {
          s4 = s3;
          if (t >= 1) {
            if (k)
              s4[a[1]] = k + 'a' - 1;
            else
              s4.erase(a[1], 1);
          } else
            k = 5;
          if (T[s4] && T[s4] != p + 1) {
            x += M[s4];
            T[s4] = p + 1;
          }
        }
      }
    }
    cout << x;
  }
  return 0;
}
