#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int n, f[N][2];
int v1[30][30], v2[30][30][30];
char s[N];
vector<string> res;
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  if (n >= 7) f[n][0] = 1;
  if (n >= 8) f[n][1] = 1;
  for (int i = n; i >= 7; i--) {
    if (f[i][0]) {
      v1[s[i - 1] - 'a'][s[i] - 'a'] = 1;
      if (i - 2 >= 8) f[i - 2][1] = 1;
      if (i - 2 >= 7 && (s[i - 3] != s[i - 1] || s[i - 2] != s[i]))
        f[i - 2][0] = 1;
    }
    if (f[i][1]) {
      v2[s[i - 2] - 'a'][s[i - 1] - 'a'][s[i] - 'a'] = 1;
      if (i - 3 >= 7) f[i - 2][0] = 1;
      if (i - 3 >= 8 &&
          (s[i - 5] != s[i - 2] || s[i - 4] != s[i - 1] || s[i - 3] != s[i]))
        f[i - 3][1] = 1;
    }
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      if (v1[i][j]) {
        string tmp;
        tmp += i + 'a';
        tmp += j + 'a';
        res.push_back(tmp);
      }
      for (int k = 0; k < 26; k++) {
        if (v2[i][j][k]) {
          string tmp;
          tmp += i + 'a';
          tmp += j + 'a';
          tmp += k + 'a';
          res.push_back(tmp);
        }
      }
    }
  }
  printf("%d\n", res.size());
  sort(res.begin(), res.end());
  for (string str : res) {
    cout << str << endl;
  }
  return 0;
}
