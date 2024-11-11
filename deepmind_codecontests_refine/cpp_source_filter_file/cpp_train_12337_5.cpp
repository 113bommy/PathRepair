#include <bits/stdc++.h>
using namespace std;
int ch[27][200005];
char chg[27] = {'a', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
                'i', 'g', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
                'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
int main() {
  int n, m;
  memset(ch, 0, sizeof(ch));
  cin >> n >> m;
  char s[200005];
  scanf("%s", s);
  for (int i = 0; i < n; i++) {
    int j = s[i] - 'a' + 1;
    ch[j][0]++;
    ch[j][1] = j;
    ch[j][ch[j][0] + 1] = i;
  }
  while (m--) {
    char a, b;
    cin >> a >> b;
    for (int i = 0; i <= 26; i++) {
      if (ch[i][1] == (a - 'a' + 1)) {
        ch[i][1] = b - 'a' + 1;
      } else if (ch[i][1] == (b - 'a' + 1)) {
        ch[i][1] = a - 'a' + 1;
      }
    }
  }
  char ans[200005];
  int num = 0;
  for (int i = 1; i <= 26; i++) {
    if (ch[i][0] > 0) {
      for (int j = 2; j <= ch[i][0] + 1; j++) {
        ans[ch[i][j]] = chg[ch[i][1]];
      }
    }
  }
  ans[n] = '\0';
  cout << ans << endl;
}
