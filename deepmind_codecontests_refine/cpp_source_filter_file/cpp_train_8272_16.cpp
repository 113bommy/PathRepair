#include <bits/stdc++.h>
using namespace std;
char s[1000001];
int n;
int k;
int pf[1000001];
void pref() {
  pf[0] = 0;
  for (int i = 1; i < n; i++) {
    int prev = pf[i - 1];
    while (prev > 0 && s[i] != s[prev]) {
      prev = pf[prev - 1];
    }
    if (s[i] == s[prev]) prev++;
    pf[i] = prev;
  }
}
int main() {
  scanf("%d %d\n", &n, &k);
  scanf("%s\n", s);
  pref();
  for (int i = 0; i < n; i++) {
    int curr = i + 1 - pf[i];
    int R = (i + 1) / curr;
    int Q = (i + 1) % R;
    if (Q == 0) {
      if ((R / k) - (R % k) >= 0) {
        printf("1");
      } else {
        printf("0");
      }
    } else {
      if ((R / k) - (R % k) > 0) {
        printf("1");
      } else {
        printf("0");
      }
    }
  }
  return 0;
}
