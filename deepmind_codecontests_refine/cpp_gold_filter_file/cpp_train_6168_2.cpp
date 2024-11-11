#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
char str[N];
bool in[200];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m, cnt = 0;
    memset(in, 0, sizeof in);
    cin >> n >> m;
    scanf("%s", str + 1);
    sort(str + 1, str + n + 1);
    for (int i = 1; i <= n; ++i) {
      if (!in[str[i]]) {
        in[str[i]] = 1;
        cnt++;
      }
    }
    if (cnt == 1) {
      for (int i = 1; i <= n / m; ++i) cout << str[1];
      if (n % m) cout << str[1];
      cout << endl;
    } else if (cnt == 2) {
      if (str[m] != str[1]) {
        cout << str[m] << endl;
      } else {
        cout << str[1];
        if (str[m + 1] == str[1]) {
          for (int i = m + 1; i <= n; ++i) cout << str[i];
          cout << endl;
        } else {
          int t = n - m;
          for (int i = 1; i <= t / m; ++i) cout << str[n];
          if (t % m) cout << str[n];
          cout << endl;
        }
      }
    } else {
      if (str[1] == str[m]) {
        for (int i = m; i <= n; ++i) cout << str[i];
        cout << endl;
      } else {
        cout << str[m] << endl;
      }
    }
  }
  return 0;
}
