#include <bits/stdc++.h>
using namespace std;
void sort(char *p, int l, int u) {
  int i, j;
  for (i = l; i < u - 1; i++)
    for (j = i + 1; j < u; j++) {
      if (*(p + i) > *(p + j)) {
        char t = *(p + i);
        *(p + i) = *(p + j);
        *(p + j) = t;
      }
    }
}
int check(char b[], int m) {
  int i;
  if (b[0] > b[m / 2]) {
    for (i = 1; i < m / 2; i++) {
      if (b[i] < b[i + m / 2]) break;
    }
  } else if (b[0] < b[m / 2]) {
    for (i = 1; i < m / 2; i++) {
      if (b[i] > b[i + m / 2]) break;
    }
  }
  if (i >= m / 2)
    return (0);
  else
    return (1);
}
int main() {
  int n;
  cin >> n;
  int k = 2 * n;
  char a[k + 1];
  int i, j;
  cin >> a;
  sort(a, 0, n);
  sort(a, n, k);
  int t = check(a, k);
  if (t == 0)
    cout << "YES";
  else
    cout << "NO";
  return (0);
}
