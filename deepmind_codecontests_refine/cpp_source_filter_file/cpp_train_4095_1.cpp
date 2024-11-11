#include <bits/stdc++.h>
int temp;
using namespace std;
int main() {
  int k;
  int a[27][27];
  for (int i = 0; i <= 26; i++)
    for (int j = 0; j <= 26; j++) a[i][j] = 0;
  string s;
  cin >> s;
  cin >> k;
  string b[14];
  for (int i = 0; i < k; i++) {
    cin >> b[i];
  }
  int count = 0;
  int counta = 0;
  int countb = 0;
  for (int i = 0; i < k; i++) {
    string cur = b[i];
    int start = -1;
    int end = -1;
    int flag = 0;
    counta = countb = 0;
    for (int j = 0; j < s.size(); j++) {
      if (s[j] == cur[0] || s[j] == cur[1]) {
        if (!flag) {
          flag = 1;
          start = i;
        }
        end = i;
        if (s[j] == cur[0])
          counta++;
        else
          countb++;
      } else {
        flag = 0;
        count += min(counta, countb);
        counta = countb = 0;
      }
    }
  }
  count += min(counta, countb);
  cout << count << "\n";
  return 0;
}
