#include <bits/stdc++.h>
using namespace std;
void check(vector<long long>& a) {
  for (long long i = 0; i <= a.size() - 1; i++) {
    printf("%I64d", a[i]);
    printf(" ");
  }
  printf("\n");
}
void check(long long a[], long long n) {
  for (long long i = 0; i <= n - 1; i++) {
    printf("%I64d", a[i]);
    printf(" ");
  }
  printf("\n");
}
long long t, n, win;
string str;
int main() {
  scanf("%I64d", &t);
  while (t--) {
    scanf("%I64d", &n);
    cin >> str;
    str = '0' + str;
    win = 0;
    if (n & 1) {
      for (int i = 1; i <= n; i += 2) {
        if (((str[i] - '0') & 1)) {
          win = 1;
          break;
        }
      }
      if (!win) {
        win = 2;
      }
    } else {
      for (int i = 2; i <= n; i += 2) {
        if (!((str[i] - '0') & 1)) {
          win = 2;
          break;
        }
      }
      if (!win) {
        win = 1;
      }
    }
    printf("%I64d", win);
    printf("\n");
  }
}
