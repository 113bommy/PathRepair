#include <bits/stdc++.h>
using namespace std;
int const maxn = 4e5 + 5;
int num[maxn];
char s[maxn];
map<char, int> m;
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i <= 26; i++) {
    num[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    num[s[i] - 'a']++;
  }
  if (n == m) {
    return 0;
  }
  int last = 0;
  int mark = 0;
  for (int i = 0; i <= 26; i++) {
    if (m - num[i] >= 0) {
      m -= num[i];
    } else {
      last = m;
      mark = i;
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    if (s[i] - 'a' < mark) {
      s[i] = 'A';
    } else if (s[i] - 'a' == mark && last > 0) {
      s[i] = 'A';
      last--;
    }
  }
  for (int i = 0; i < n; i++) {
    if (s[i] != 'A') cout << s[i];
  }
  cout << endl;
}
