#include <bits/stdc++.h>
using namespace std;
char ch[2020], ans[2020];
int use[2020];
int main() {
  int a, b, c, T;
  cin >> T;
  while (T--) {
    memset(use, 0, sizeof(use));
    for (int i = 0; i <= 30; i++) ans[i] = ' ';
    scanf("%s", ch + 1);
    int tmp = 26, fir = 27, end = 27, flag = 0;
    for (int i = 1; i <= strlen(ch + 1); i++) {
      if (use[ch[i] - 'a'] == 0) {
        if (ans[tmp + 1] == ' ')
          ans[++tmp] = ch[i];
        else if (ans[tmp - 1] == ' ')
          ans[--tmp] = ch[i];
        else {
          flag = 1;
          break;
        }
        fir = min(fir, tmp);
        use[ch[i] - 'a'] = 1;
      } else {
        if (ans[tmp - 1] == ch[i]) {
          tmp = tmp - 1;
        } else if (ans[tmp + 1] == ch[i]) {
          tmp = tmp + 1;
        } else {
          flag = 1;
          break;
        }
      }
      end = max(end, tmp);
    }
    if (flag == 1) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    for (int i = fir; i <= end; i++) {
      if (ans[i] == ' ') break;
      cout << ans[i];
    }
    for (int i = 0; i < 26; i++)
      if (use[i] == 0) cout << (char)(i + 'a');
    cout << endl;
  }
}
