#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[10];
  char s[1004];
  scanf("%d", &n);
  scanf("%s", s);
  for (int i = 0; i < 10; i++) a[i] = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0' || s[i] == '1') continue;
    if (s[i] == '2') a[2]++;
    if (s[i] == '3') a[3]++;
    if (s[i] == '4') a[2] += 2, a[3] += 1;
    if (s[i] == '5') a[5]++;
    if (s[i] == '6') a[3]++, a[5]++;
    if (s[i] == '7') a[7]++;
    if (s[i] == '8') a[2] += 3, a[7]++;
    if (s[i] == '9') a[3] += 2, a[2] += 1, a[7]++;
  }
  for (int i = int(7); i >= int(2); i--) {
    for (int j = 0; j < a[i]; j++) printf("%d", i);
  }
  return 0;
}
