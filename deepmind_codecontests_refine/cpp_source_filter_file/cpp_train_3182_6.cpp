#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int K = 1e6 + 7;
const int mod = 1e9 + 7;
int a[K];
char ss[K];
int main(void) {
  int n, ff = 1;
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  getchar();
  for (int i = 1; i <= n; i++) {
    gets(ss);
    int len = strlen(ss), tmp = 0;
    for (int j = 0; j < len; j++)
      if (ss[j] == 'a' || ss[j] == 'e' || ss[j] == 'i' || ss[j] == 'o' ||
          ss[j] == 'u' || ss[i] == 'y')
        tmp++;
    if (tmp != a[i]) {
      ff = 0;
      break;
    }
  }
  if (ff)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
