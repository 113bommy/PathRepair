#include <bits/stdc++.h>
using namespace std;
int A[105][105];
int main() {
  int n;
  int ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < n; j++) {
      if (s[j] == 'C') {
        A[i][j] = 1;
      } else {
        A[i][j] = 0;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (A[i][j] == 1) {
        cnt++;
      }
    }
    ans += (cnt * (cnt - 1)) / 2;
  }
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (A[j][i] == 1) {
        cnt++;
      }
    }
    ans += (cnt * (cnt - 1)) / 2;
  }
  cout << ans;
}
