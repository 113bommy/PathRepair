#include <bits/stdc++.h>
using namespace std;
vector<long long> v1, v2;
list<long long>::iterator it;
int main() {
  long long n, t, sum, m;
  scanf("%lld%lld", &n, &m);
  char str[n + 4][100], str1[m + 4][100];
  for (int i = 0; i < n; i++) {
    scanf("%s", str[i]);
  }
  for (int i = 0; i < m; i++) {
    scanf("%s", str1[i]);
  }
  scanf("%lld", &t);
  long long tt;
  while (t--) {
    char str2[10000], str3[10000];
    scanf("%lld", &tt);
    long long qq, ww;
    qq = tt % n;
    ww = tt % m;
    if (qq == 0 && ww == 0) {
      strcpy(str2, str[n - 1]);
      strcpy(str3, str1[m - 1]);
      strcat(str2, str3);
      printf("%s\n", str2);
    }
    if (qq == 0) {
      strcpy(str2, str[n - 1]);
      strcpy(str3, str1[ww - 1]);
      strcat(str2, str3);
      printf("%s\n", str2);
    } else if (ww == 0) {
      strcpy(str2, str[qq - 1]);
      strcpy(str3, str1[m - 1]);
      strcat(str2, str3);
      printf("%s\n", str2);
    } else {
      strcpy(str2, str[qq - 1]);
      strcpy(str3, str1[ww - 1]);
      strcat(str2, str3);
      printf("%s\n", str2);
    }
  }
}
