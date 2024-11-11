#include <bits/stdc++.h>
using namespace std;
int ri() {
  int x;
  scanf("%d", &x);
  return x;
}
long long rll() {
  long long x;
  scanf("%lld", &x);
  return x;
}
void solve() {
  int n = ri();
  vector<string> mas(n);
  for (int i = (int)(0); i <= (int)(n - 1); i++) cin >> mas[i];
  string s;
  string omg;
  cin >> s;
  omg = s;
  string luck;
  cin >> luck;
  for (int i = (int)(0); i <= (int)(n - 1); i++) {
    if (mas[i].length() > s.length()) continue;
    for (int j = (int)(0); j <= (int)(s.length() - mas[i].length()); j++) {
      bool ans = true;
      int t = 0;
      for (int k = (int)(j); k <= (int)(j + mas[i].length() - 1); k++)
        if (tolower(s[k]) != tolower(mas[i][t++])) ans = false;
      if (ans) {
        for (int k = (int)(j); k <= (int)(j + mas[i].length() - 1); k++)
          if (s[k] == luck[0]) {
            if (luck[0] == 'a') {
              if (s[k] >= 'A' && s[k] <= 'Z')
                omg[k] = 'B';
              else
                omg[k] = 'b';
            } else {
              if (s[k] >= 'A' && s[k] <= 'Z')
                omg[k] = 'A';
              else
                omg[k] = 'a';
            }
          } else {
            if (s[k] >= 'A' && s[k] <= 'Z')
              omg[k] = toupper(luck[0]);
            else
              omg[k] = tolower(luck[0]);
          }
      }
    }
  }
  cout << omg;
}
int main() {
  solve();
  return 0;
}
