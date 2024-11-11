#include <bits/stdc++.h>
using namespace std;
int i, j, qan, n, m, k, l, p;
bool mark[102];
char s;
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> s;
    if (s == '*') {
      mark[i] = true;
    }
  }
  qan = (n - 5) / 4;
  for (i = 0; i <= qan; i++) {
    for (j = 1; j <= n - 4 - 4 * i; j++) {
      if (mark[j] == true && mark[j + i + 1] == true &&
          mark[j + 2 * i + 2] == true && mark[j + 3 * i + 3] == true &&
          mark[4 * i + j + 4] == true) {
        cout << "yes" << endl;
        return 0;
      }
    }
  }
  cout << "no" << endl;
  return 0;
}
