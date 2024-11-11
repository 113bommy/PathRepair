#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[1000000];
  long a[37];
  long long n;
  int i = 0;
  while (gets(s) != NULL) {
    n = 0;
    for (i = 0; i < 37; ++i) a[i] = 0;
    i = 0;
    while (s[i] != '\0') {
      if (s[i] >= '0' && s[i] <= '9')
        a[s[i] - '0']++;
      else if (s[i] >= 'a' && s[i] <= 'z')
        a[s[i] - 'a' + 10]++;
      i++;
    }
    for (i = 0; i < 37; ++i) n += a[i] * a[i];
    cout << n << endl;
  }
  return 0;
}
