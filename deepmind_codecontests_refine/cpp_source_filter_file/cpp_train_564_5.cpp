#include <bits/stdc++.h>
int a[27], b[27];
using namespace std;
int main() {
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  char s[1000], t[1000];
  cin >> s >> t;
  int ls, lt, i, f = 0;
  lt = strlen(t);
  ls = strlen(s);
  for (int i = 0; i < ls; i++) {
    a[s[i] - 'a']++;
  }
  for (int i = 0; i < lt; i++) {
    b[t[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++) {
    if (a[i] < b[i]) {
      f = 1;
      break;
    }
  }
  if (f == 1) {
    cout << "need tree" << endl;
  } else if (ls == lt) {
    cout << "array" << endl;
  } else {
    int p = 0, j = 0;
    for (i = 0; i < lt; i++) {
      while (t[i] != s[j] && j < ls) {
        j++;
      }
      if (j >= ls) {
        p = 1;
        break;
      }
      j++;
    }
    if (p == 1) {
      cout << "both" << endl;
    } else {
      cout << "automation" << endl;
    }
  }
}
