#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  char *s;
  s = (char *)malloc(sizeof(char) * (m + 1));
  int **a;
  a = (int **)malloc(sizeof(int *) * 3);
  a[0] = (int *)malloc(sizeof(int) * 2);
  a[1] = (int *)malloc(sizeof(int) * 2);
  a[2] = (int *)malloc(sizeof(int) * 2);
  int q = -1;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++) {
      if (s[j] == '*') {
        a[++q][0] = i;
        a[q][1] = j;
      }
    }
  }
  if (a[0][0] == a[1][0]) {
    cout << a[2][0] + 1 << " ";
  } else if (a[0][0] == a[2][0]) {
    cout << a[1][0] + 1 << " ";
  } else {
    cout << a[0][0] + 1 << " ";
  }
  if (a[0][1] == a[1][1]) {
    cout << a[2][1] + 1 << " ";
  } else if (a[0][1] == a[2][1]) {
    cout << a[1][1] + 1 << " ";
  } else {
    cout << a[0][1] + 1 << " ";
  }
}
