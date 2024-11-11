#include <bits/stdc++.h>
using namespace std;
template <class T>
void print(const T niz[], const int siz) {
  for (int i = 0; i < siz; i++) cout << niz[i] << " ";
  cout << endl;
}
string x;
int n;
int blok[100005];
int desno[100005][2];
int res[100005];
int dp[2];
string y;
int sol[100005];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> x;
  y = x;
  n = x.length();
  reverse(y.begin(), y.end());
  int maks = 0;
  for (int i = 0; i < n; i++) {
    int tr = 0;
    if (y[i] == '0') {
      tr = max(tr, max(dp[1], dp[0]) + 1);
    } else
      tr = max(tr, dp[1] + 1);
    dp[y[i] - '0'] = max(dp[y[i] - '0'], tr);
    maks = max(maks, tr);
    res[n - i - 1] = maks;
  }
  for (int i = n - 1; i >= 0; i--) {
    if (x[i] == '0')
      desno[i][0] = desno[i + 1][0] + 1;
    else
      desno[i][1] = desno[i + 1][1] + 1;
  }
  for (int i = 0; i < n; i++) {
    if (x[i] == '0') continue;
    if (i > 0 && x[i - 1] == '1') continue;
    int sta = res[i];
    int sta2 = res[i + desno[i][1]];
    int kolkomoz = sta - sta2;
    for (int j = i; j < i + kolkomoz; j++) sol[j] = 1;
  }
  for (int i = 0; i < n; i++) {
    if (sol[i] == 1)
      cout << 0;
    else
      cout << x[i];
  }
  return 0;
}
