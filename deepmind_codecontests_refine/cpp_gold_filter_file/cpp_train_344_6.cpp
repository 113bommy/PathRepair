#include <bits/stdc++.h>
using namespace std;
char s[5100];
char mas[5100];
int l, sum;
int b[30];
bool rec(int x) {
  if (x == sum && sum > l) {
    return 1;
  }
  if (x == sum && sum <= l) {
    if (mas[x] > s[x])
      return 1;
    else
      return 0;
  }
  if (x < sum) {
    bool fl = 0;
    if (b[s[x] - 'a'] > 0) {
      mas[x] = s[x];
      b[s[x] - 'a']--;
      if (rec(x + 1)) {
        return 1;
      } else
        b[s[x] - 'a']++;
    }
    {
      for (int i = s[x] - 'a' + 1; i < 26; i++) {
        if (b[i] > 0) {
          mas[x] = i + 'a';
          b[i]--;
          for (int z = x + 1; z < sum; z++) {
            for (int j = 0; j < 26; j++) {
              if (b[j] > 0) {
                b[j]--;
                mas[z] = j + 'a';
                break;
              }
            }
          }
          return 1;
        }
      }
      return 0;
    }
  }
}
int main() {
  cin >> s;
  l = strlen(s);
  sum = l;
  for (int i = 0; i < l; i++) b[s[i] - 'a']++;
  cin >> s;
  l = strlen(s);
  for (int i = l; i < sum; i++) s[i] = 'a';
  if (rec(0)) {
    for (int i = 0; i < sum; i++) printf("%c", mas[i]);
    printf("\n");
  } else
    cout << -1 << endl;
}
