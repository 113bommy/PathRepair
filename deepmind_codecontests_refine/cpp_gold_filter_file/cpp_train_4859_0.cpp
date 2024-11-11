#include <bits/stdc++.h>
using namespace std;
int n;
long long fin, pi, ran[2][200005];
string s;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    cin >> s;
    int nowl = 0, nowr = 0;
    for (int j = 0; j < s.size(); j++) {
      if (s[j] == '(') {
        nowl++;
      } else if (s[j] == ')') {
        if (nowl == 0) {
          nowr++;
        } else {
          nowl--;
        }
      }
    }
    if (nowl == 0 && nowr == 0) {
      pi++;
    } else if (nowl == 0)
      ran[1][nowr]++;
    else if (nowr == 0)
      ran[0][nowl]++;
  }
  for (int i = 1; i <= 200004; ++i) {
    fin += ran[0][i] * ran[1][i];
  }
  printf("%lld\n", fin + pi * pi);
  return 0;
}
