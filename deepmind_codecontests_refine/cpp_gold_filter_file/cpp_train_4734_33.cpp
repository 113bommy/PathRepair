#include <bits/stdc++.h>
using namespace std;
void solve() {
  char ch[200];
  cin.getline(ch, 200);
  int i = 0, j = 0;
  while (ch[i] != '\0') {
    int chk = 0;
    if (ch[i] == ' ') {
      for (j = i; ch[j - 1] != '\0'; j++) ch[j] = ch[j + 1];
      chk = 1;
    }
    if (chk == 0) i++;
  }
  if (ch[i - 2] == 'a' || ch[i - 2] == 'e' || ch[i - 2] == 'i' ||
      ch[i - 2] == 'o' || ch[i - 2] == 'u' || ch[i - 2] == 'y' ||
      ch[i - 2] == 'A' || ch[i - 2] == 'E' || ch[i - 2] == 'I' ||
      ch[i - 2] == 'O' || ch[i - 2] == 'U' || ch[i - 2] == 'Y')
    cout << "YES\n";
  else
    cout << "NO\n";
}
int main() {
  int n = 1;
  while (n--) solve();
  return 0;
}
