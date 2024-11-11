#include <bits/stdc++.h>
using namespace std;
int len[100500], num[100500];
bool check(char a, char b) {
  if (a == '(' && b == ')') return true;
  if (a == '[' && b == ']') return true;
  return false;
}
int main() {
  string str;
  cin >> str;
  for (int i = str.size() - 2; i >= 0; i--) {
    if (str[i] == ')' || str[i] == ']') continue;
    int pos = i + 1 + len[i + 1];
    if (check(str[i], str[pos])) len[i] = pos - i + 1 + len[pos + 1];
  }
  num[0] = str[0] == '[';
  for (int i = 1; i < str.size(); i++) num[i] = num[i - 1] + (str[i] == '[');
  int ans = 0, pos;
  for (int i = 0; i < str.size(); i++) {
    if (num[i + len[i] - 1] - num[i] >= ans) {
      ans = num[i + len[i] - 1] - num[i - 1];
      pos = i;
    }
  }
  printf("%d\n", ans);
  if (ans != 0)
    for (int i = pos; i < pos + len[pos]; i++) printf("%c", str[i]);
  puts("");
  return 0;
}
