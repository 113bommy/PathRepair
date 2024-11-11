#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int inf = 1e9 + 7;
char a[2000];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", a + 1);
    int n = strlen(a + 1);
    if (a[n] == 'o' && a[n - 1] == 'p') {
      cout << "FILIPINO" << endl;
    } else if ((a[n] == 'u' && a[n - 1] == 's' && a[n - 2] == 'e' &&
                a[n - 3] == 'd') ||
               (a[n] == 'u' && a[n - 1] == 's' && a[n - 2] == 'a' &&
                a[n - 3] == 'm')) {
      cout << "JANPAESE" << endl;
    } else if (a[n] == 'a' && a[n - 1] == 'd' && a[n - 2] == 'i' &&
               a[n - 3] == 'n' && a[n - 4] == 'm') {
      cout << "KOREAN" << endl;
    }
  }
  return 0;
}
