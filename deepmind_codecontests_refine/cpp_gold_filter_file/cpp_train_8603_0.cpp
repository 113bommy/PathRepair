#include <bits/stdc++.h>
using namespace std;
char input[27];
int cnt = 0;
bool used[27];
char ans[100001];
int main() {
  string s;
  int n, k;
  int i, j;
  cin >> n >> k;
  cin >> s;
  for (i = 0; i < s.length(); i++)
    if (!used[s[i] - 'a' + 1]) used[s[i] - 'a' + 1] = true, input[cnt++] = s[i];
  sort(input, input + cnt);
  if (k > n) {
    for (i = 0; i < s.length(); i++) cout << s[i];
    for (i = s.length(); i < k; i++) cout << input[0];
    cout << endl;
  } else {
    int add = 1;
    i = k;
    while (i > 0) {
      int po;
      if (add) {
        for (j = 0; j < cnt; j++)
          if (input[j] == s[i - 1]) break;
        if (j == cnt - 1)
          ans[i] = input[0];
        else
          ans[i] = input[j + 1], add = 0;
      } else
        ans[i] = s[i - 1];
      i--;
    }
    for (i = 1; i <= k; i++) cout << ans[i];
    cout << endl;
  }
  return 0;
}
