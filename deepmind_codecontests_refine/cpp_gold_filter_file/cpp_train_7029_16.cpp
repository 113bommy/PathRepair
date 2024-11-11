#include <bits/stdc++.h>
using namespace std;
int check2(int **mas, int a, int b, int n) {
  int **p;
  int **g;
  for (p = mas; p - mas < n - 1; p++)
    for (g = p + 1; g - mas < n; g++) {
      if (*(*g + a) == *(*p + a))
        if (*(*g + b) == *(*p + b)) return 0;
    }
  return 1;
}
int swap2(int **mas, int n) {
  int a, b;
  for (a = 0; a < 5; a++)
    for (b = a + 1; b < 6; b++) {
      if (!check2(mas, a, b, n)) return 0;
    }
  return 1;
}
int check1(int **mas, int a, int b, int c, int d, int n) {
  int **p;
  int **g;
  for (p = mas; p - mas < n - 1; p++)
    for (g = p + 1; g - mas < n; g++) {
      if (*(*g + a) == *(*p + a))
        if (*(*g + b) == *(*p + b))
          if (*(*g + c) == *(*p + c))
            if (*(*g + d) == *(*p + d)) return 0;
    }
  return 1;
}
int swap1(int **mas, int n) {
  int a, b, c, d;
  for (a = 0; a < 3; a++)
    for (b = a + 1; b < 4; b++)
      for (c = b + 1; c < 5; c++)
        for (d = c + 1; d < 6; d++) {
          if (!check1(mas, a, b, c, d, n)) return 0;
        }
  return 1;
}
int main() {
  int n, i, buf;
  int *p;
  int **m;
  cin >> n;
  int **mas = new int *[n];
  for (i = 0; i < n; i++) mas[i] = new int[6];
  for (m = mas; m - mas < n; m++) {
    cin >> buf;
    for (p = *m; p - *m < 6; p++) {
      *p = (buf % 10);
      buf = buf / 10;
    }
  }
  if (n == 1) {
    cout << 6;
    return 0;
  }
  if (swap2(mas, n)) {
    cout << 2;
    return 0;
  }
  if (swap1(mas, n)) {
    cout << 1;
    return 0;
  }
  cout << 0;
  return 0;
}
