#include <bits/stdc++.h>
using namespace std;
void Main();
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  Main();
  return 0;
}
char s[305][304];
void Main() {
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        s[i][j] = '0';
      }
      s[i][n] = '\0';
    }
    for (int i = 0; i < n && k; i++) {
      int a = i;
      for (int j = 0; j < n && k; j++) {
        s[a][j] = '1';
        a = (a + 1) % n;
        k--;
      }
    }
    int mxa = -1, mna = INT_MAX;
    for (int i = 0; i < n; i++) {
      int cnt = 0;
      for (int j = 0; j < n; j++) {
        if (s[i][j] == '0') {
          cnt++;
        }
      }
      mxa = max(mxa, cnt);
      mna = min(mna, cnt);
    }
    int mxb = -1, mnb = INT_MAX;
    for (int i = 0; i < n; i++) {
      int cnt = 0;
      for (int j = 0; j < n; j++) {
        if (s[j][i] == '0') {
          cnt++;
        }
      }
      mxb = max(mxb, cnt);
      mnb = min(mnb, cnt);
    }
    cout << (mxa - mna) + (mxb - mnb) << '\n';
    for (int i = 0; i < n; i++) {
      cout << s[i] << '\n';
    }
  }
}
