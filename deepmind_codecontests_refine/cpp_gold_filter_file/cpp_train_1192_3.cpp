#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s = "qwertyuiopasdfghjkl;zxcvbnm,./";
  char c;
  cin >> c;
  string a;
  cin >> a;
  for (int i = 0; ((1 > 0) ? i <= a.size() - 1 : i >= a.size() - 1); i += 1) {
    int j = 0;
    while (s[j] != a[i]) j++;
    cout << (c == 'R' ? s[j - 1] : s[j + 1]);
  }
}
