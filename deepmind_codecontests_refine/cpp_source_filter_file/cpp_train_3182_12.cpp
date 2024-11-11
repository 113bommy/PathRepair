#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int N = 6000010;
const long long mod = 1000000007;
const long long inf = 1000000000000000000LL;
int n, m;
int a[110];
char s[110];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  gets(s);
  int flag = 0;
  for (int i = 0; i < n; i++) {
    gets(s);
    for (int j = 0; j < strlen(s); j++) {
      if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' ||
          s[j] == 'u' || s[j] == 'u')
        a[i]--;
    }
    if (a[i]) flag = 1;
  }
  if (flag)
    printf("NO\n");
  else
    printf("YES\n");
  return 0;
}
