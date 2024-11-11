#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, n, len;
  cin >> n;
  n += 1;
  char s[n], ch[n];
  cin >> s;
  len = strlen(s);
  k = 0;
  for (i = 0; i < len - 1; i++) {
    if (s[i] > s[i + 1]) {
      k = i;
      break;
    }
  }
  for (i = 0, j = 0; i < len; i++) {
    if (i != k) {
      ch[j] = s[i];
      j++;
    }
  }
  ch[j] = '\0';
  cout << ch << endl;
  return 0;
}
