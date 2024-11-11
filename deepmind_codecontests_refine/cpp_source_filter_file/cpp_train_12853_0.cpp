#include <bits/stdc++.h>
using namespace std;
bool used[105];
int main() {
  int n, m;
  cin >> n >> m;
  string s[105];
  bool flag;
  int c = 0;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < m; i++) {
    flag = false;
    for (int j = 2; j <= n; j++) {
      if (used[j] == false and s[j][i] < s[j - 1][i]) {
        flag = true;
      }
    }
    if (flag == false) {
      for (int j = 2; j <= n; j++) {
        if (used[j] == false and s[j][i] > s[j - 1][i]) {
          used[j] == true;
        }
      }
    } else {
      c++;
    }
  }
  cout << c;
}
