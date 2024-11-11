#include <bits/stdc++.h>
using namespace std;
int n, ans = 1000000007, rh, rt, sufh[(int)(2e5 + 10)], suft[(int)(2e5 + 10)],
       preh[(int)(2e5 + 10)], pret[(int)(2e5 + 10)], h, t;
string str;
int main() {
  cin >> n >> str;
  str = " " + str;
  for (int i = 1; i <= n; i++) {
    if (str[i] == 'H')
      h++;
    else
      t++;
    preh[i] = preh[i - 1] + (str[i] == 'H');
    pret[i] = preh[i - 1] + (str[i] == 'T');
  }
  for (int i = n; i >= 1; i--) {
    sufh[i] = sufh[i + 1] + (str[i] == 'H');
    suft[i] = suft[i + 1] + (str[i] == 'T');
  }
  for (int l = 0; l <= n; l++) {
    rh = n - (h - l) + 1;
    rt = n - (t - l) + 1;
    ans = min(ans, min(preh[l] + sufh[rt], pret[l] + suft[rh]));
  }
  cout << ans << '\n';
}
