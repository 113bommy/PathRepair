#include <bits/stdc++.h>
using namespace std;
string s;
int check() {
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '.') return i;
  }
  return -1;
}
string a, b;
int main() {
  int m, n, i, j, k;
  ios::sync_with_stdio(false);
  ;
  cin >> s;
  int dot = check();
  if (dot == -1) {
  l:;
    if (s.length() == 1) {
      cout << s << endl;
      return 0;
    }
    j = 0, k = s.length() - 1;
    int len = s.length() - 1;
    while (s[j] == '0') j++, len--;
    while (s[k] == '0') k--;
    if (k < j) return puts("0");
    printf("%d", s[j] - '0');
    if (j + 1 <= k) printf(".");
    for (i = j + 1; i <= k; i++) printf("%d", s[i] - '0');
    if (len != 0) printf("E%d\n", len);
    return 0;
  } else {
    i = 0;
    while (s[i] == '0') i++;
    for (; i < dot; i++) a += s[i];
    k = s.length() - 1;
    while (s[k] == '0') k--;
    for (j = dot + 1; j <= k; j++) b += s[j];
    if (a == "" && b == "") return puts("0");
    if (b == "") {
      s = a;
      goto l;
    }
    if (a == "") {
      int len = -1;
      i = 0;
      while (b[i] == '0') i++, len--;
      cout << b[i];
      i++;
      if (i < b.length()) cout << '.';
      for (; i < b.length(); i++) cout << b[i];
      if (len != 0) cout << "E" << len << endl;
      return 0;
    }
    cout << a[0] << '.';
    for (i = 1; i < a.length(); i++) cout << a[i];
    for (i = 0; i < b.length(); i++) cout << b[i];
    if (a.length() != 1) cout << "E" << a.length() - 1 << endl;
  }
}
