#include <bits/stdc++.h>
using namespace std;
const int MAX = 500005;
char s[MAX];
double c[MAX];
double ans;
int main() {
  c[1] = 1.0;
  for (int i = 2; i < MAX; ++i) c[i] = c[i - 1] + 1.0 / i;
  scanf("%s", s);
  int len = strlen(s);
  double sum;
  for (int i = 0; i < len; ++i) {
    sum += c[len - i];
    sum -= c[i];
    if (s[i] == 'I' || s[i] == 'E' || s[i] == 'A' || s[i] == 'O' ||
        s[i] == 'U' || s[i] == 'Y') {
      ans += sum;
    }
  }
  printf("%.8f\n", ans);
  return 0;
}
