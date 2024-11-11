#include <bits/stdc++.h>
using namespace std;
int t, cnt[300005][10], odd[10];
string s;
void inp() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
}
void solve(string s, int n) {
  for (int i = n; i >= 1; i--) {
    int sz = 0;
    cnt[i][s[i] - '0']--;
    for (int j = s[i] - '0' - 1; j >= 0; j--) {
      sz = 0;
      cnt[i][j]++;
      for (int k = 0; k <= 9; k++) {
        if (cnt[i][k] % 2) odd[++sz] = k;
      }
      int space = n - i;
      if (space >= sz and (space - sz) % 2 == 0) {
        int num9 = space - sz;
        cout << s.substr(1, i - 1) << j;
        for (int i = 1; i <= num9; i++) cout << "9";
        for (int u = sz; u >= 1; u--) cout << odd[u];
        cout << "\n";
        cnt[i][j]--;
        return;
      }
      cnt[i][j]--;
    }
    cnt[i][s[i] - '0']++;
  }
}
void sub1() {
  for (int i_t = 1; i_t <= t; i_t++) {
    cin >> s;
    int n = s.size();
    s = " " + s;
    for (int i = 0; i <= 9; i++) cnt[1][i] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= 9; j++) cnt[i][j] = cnt[i - 1][j];
      cnt[i][s[i] - '0']++;
    }
    if ((cnt[n][1] == 1 or (cnt[n][1] == 2 and s[n] == '1')) and
        n - cnt[n][1] == cnt[n][0]) {
      for (int i = 1; i <= n - 2; i++) cout << "9";
      cout << "\n";
      continue;
    }
    solve(s, n);
  }
}
int main() {
  inp();
  sub1();
}
