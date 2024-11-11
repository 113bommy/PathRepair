#include <bits/stdc++.h>
using namespace std;
char a[200020];
char b[200020];
int d[30];
int e[30];
long long c[30];
long long s[30];
double z;
int n;
int main() {
  scanf("%d", &n);
  scanf("%s", a);
  scanf("%s", b);
  for (int i = 0; i < n; i++) {
    s[a[i] - 'A'] += i, d[a[i] - 'A']++;
    c[b[i] - 'A'] += i, e[b[i] - 'A']++;
  }
  for (int i = 0; i < n; i++) {
    c[b[i] - 'A'] -= i, e[b[i] - 'A']--;
    z += (i + 1) * ((long long)d[b[i] - 'A'] * n - s[b[i] - 'A']);
    z += (i + 1) * ((long long)e[a[i] - 'A'] * n - c[a[i] - 'A']);
    s[a[i] - 'A'] -= i, d[a[i] - 'A']--;
  }
  printf("%.15f", (double)z / ((long long)n * (n + 1) * (2 * n + 1) / 6));
}
