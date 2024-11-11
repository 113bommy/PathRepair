#include <bits/stdc++.h>
using namespace std;
int n, k;
char str[100005];
int a[35];
int m[35];
int main() {
  cin >> n >> k;
  cin >> str;
  int c = 0;
  int len = strlen(str);
  for (int i = 0; i < len; i++) {
    if (m[str[i] - 'a'] == 0) {
      m[str[i] - 'a'] = 1;
      a[c++] = str[i] - 'a';
    }
  }
  sort(a, a + c);
  if (n < k) {
    cout << str;
    k -= len;
    while (k--) cout << (char)('a' + a[0]);
    cout << endl;
    return 0;
  }
  for (int i = k - 1; i >= 0; i--) {
    if (str[i] - 'a' == a[c - 1]) {
      str[i] = a[0] + 'a';
    } else {
      for (int j = 0; j < c; j++) {
        if (str[i] - 'a' == a[j]) {
          str[i] = a[j + 1] + 'a';
          break;
        }
      }
      break;
    }
  }
  for (int i = 0; i < k; i++) {
    printf("%c", str[i]);
  }
  cout << endl;
}
