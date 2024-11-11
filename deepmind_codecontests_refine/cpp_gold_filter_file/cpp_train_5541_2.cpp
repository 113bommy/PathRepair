#include <bits/stdc++.h>
using namespace std;
struct fruit {
  char name[33];
  int q;
};
int main() {
  int n, m;
  int i, j;
  cin >> n >> m;
  fruit f[100];
  int p[100];
  int c = 0;
  char str[33];
  int temp;
  int sum1 = 0, sum2 = 0;
  for (i = 0; i < n; i++) cin >> p[i];
  for (i = 0; i < n; i++)
    for (j = i + 1; j < n; j++) {
      if (p[i] >= p[j]) {
        temp = p[i];
        p[i] = p[j];
        p[j] = temp;
      }
    }
  for (i = 0; i < m; i++) {
    cin >> str;
    for (j = 0; j < c; j++) {
      if (strcmp(str, f[j].name) == 0) {
        f[j].q++;
        break;
      }
    }
    if (j == c) {
      strcpy(f[j].name, str);
      c++;
      f[j].q = 1;
    }
  }
  for (i = 0; i < c; i++)
    for (j = i + 1; j < c; j++) {
      if (f[i].q >= f[j].q) {
        temp = f[i].q;
        f[i].q = f[j].q;
        f[j].q = temp;
      }
    }
  for (i = 0; i < c; i++) {
    sum1 += p[i] * f[c - 1 - i].q;
    sum2 += p[n - 1 - i] * f[c - 1 - i].q;
  }
  cout << sum1 << " " << sum2;
  return 0;
}
