#include <bits/stdc++.h>
using namespace std;
char num[1111111][10];
int n, k;
double f[1111111];
double trans(char *s) {
  bool neg = false;
  char *p = s;
  if (*p == '-') {
    neg = true;
    p++;
  }
  int len = strlen(p);
  double ans = 0;
  for (int i = 0; i < len; i++) {
    ans = ans * 10 + (*p) - '0';
    p++;
  }
  if (neg) ans *= -1;
  return ans;
}
int main() {
  scanf("%d%d", &n, &k);
  int ques = 0;
  bool deter = true;
  for (int i = 0; i <= n; i++) {
    scanf("%s", num[i]);
    if (num[i][0] == '?') deter = false, ques++;
  }
  if (k == 0) {
    if (num[0][0] == '0')
      cout << "Yes";
    else if (num[0][0] == '?' && ((n + 1 - ques) & 1))
      cout << "Yes";
    else
      cout << "No";
    return 0;
  }
  if (deter == false) {
    if (n & 1)
      cout << "Yes";
    else
      cout << "No";
    return 0;
  }
  if (deter == true) {
    for (int i = 0; i <= n; i++) f[i] = trans(num[i]);
    for (int i = n; i >= 0; i--) f[i] += f[i + 1] * k;
    if (abs(f[0]) > 1e-5)
      cout << "No";
    else
      cout << "Yes";
    return 0;
  }
}
