#include <bits/stdc++.h>
using namespace std;
int itos(string a) {
  int ans = 0;
  for (int i = 0; i < a.size(); i++) {
    ans *= 10;
    ans += int(a[i] - '0');
  }
  return ans;
}
string add(string a, string b) {
  if (a.size() < b.size()) swap(a, b);
  reverse(b.begin(), b.end());
  while (b.size() != a.size()) b += "0";
  reverse(a.begin(), a.end());
  a += "0";
  b += "0";
  string ans = "";
  for (int i = 0; i < a.size(); i++) {
    ans += char(((int(a[i] - '0') + int(b[i] - '0')) % 10) + '0');
    int x = i;
    if ((int(a[i] - '0') + int(b[i] - '0')) > 9) {
      for (int j = 1; a[j + i] == '9'; j++, x++) a[i + j] = '0';
      a[x + 1] = char(int(a[x + 1] - '0') + 1 + '0');
    }
  }
  reverse(ans.begin(), ans.end());
  string c = "";
  int y = 0;
  for (int i = 0; ans[i] == '0'; i++, y++)
    ;
  for (int i = y; i < ans.size(); i++) c += ans[i];
  return c;
}
int main() {
  cout << "NTERCAL\n";
  return 0;
}
