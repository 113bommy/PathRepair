#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
char a[222][222];
bool flag[222];
int main() {
  int n, m;
  while (cin >> m >> n) {
    memset(a, 0, sizeof(a));
    map<int, bool> no;
    for (int i = 0; i < m; i++) scanf("%s", a[i]);
    vector<int> vec(n);
    bool equ = true;
    for (int i = 0; i < n; i++) {
      cin >> vec[i];
      no[vec[i] - 1] = true;
    }
    if (n == 1) {
      cout << "Yes" << endl;
      printf("%s\n", a[vec[0] - 1]);
      continue;
    }
    for (int i = 0; i < vec.size() - 1; i++) {
      if (strlen(a[vec[i] - 1]) != strlen(a[vec[i + 1] - 1])) {
        equ = false;
        break;
      }
    }
    if (!equ) {
      cout << "No" << endl;
      continue;
    }
    memset(flag, true, sizeof(flag));
    int len = strlen(a[vec[0] - 1]);
    for (int i = 0; i < len; i++) {
      for (int j = 0; j < vec.size() - 1; j++) {
        if (a[vec[j] - 1][i] != a[vec[j + 1] - 1][i]) {
          flag[i] = false;
          break;
        }
      }
    }
    string cmp = "";
    for (int i = 0; i < len; i++) {
      if (!flag[i])
        cmp += "?";
      else
        cmp += a[vec[0] - 1][i];
    }
    bool yes = true;
    for (int i = 0; i < m; i++) {
      if (no[i]) continue;
      len = strlen(a[i]);
      if (len != cmp.size()) continue;
      int tot = 0;
      for (int j = 0; j < cmp.size(); j++) {
        if (cmp[j] == a[i][j] || cmp[j] == '?') tot++;
      }
      if (tot == len) {
        yes = false;
        break;
      }
    }
    if (yes) {
      cout << "Yes" << endl;
      cout << cmp << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
