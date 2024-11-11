#include <bits/stdc++.h>
using namespace std;
char buf[1010];
int X, Y;
int r[1010][1010], d[1010][1010], a[1010][1010];
int check(void) {
  int ans = 0, i, j;
  for ((i) = 0; (i) < (int)(X); (i)++)
    for ((j) = 0; (j) < (int)(Y); (j)++) {
      if (i + 1 < X && a[i + 1][j] == (a[i][j] ^ d[i][j])) ans++;
      if (j + 1 < Y && a[i][j + 1] == (a[i][j] ^ r[i][j])) ans++;
    }
  return ans;
}
void left_to_right(void) {
  int i, j;
  for ((j) = 0; (j) < (int)(Y); (j)++) {
    a[0][j] = 0;
    for (i = 1; i < X; i++) a[i][j] = (a[i - 1][j] ^ d[i - 1][j]);
    if (j > 0) {
      int good = 0, bad = 0;
      for ((i) = 0; (i) < (int)(X); (i)++)
        if (a[i][j] == (a[i][j - 1] ^ r[i][j - 1]))
          good++;
        else
          bad++;
      if (good < bad)
        for ((i) = 0; (i) < (int)(X); (i)++) a[i][j] = (a[i][j] ^ 1);
    }
  }
}
void top_to_down(void) {
  int i, j;
  for ((i) = 0; (i) < (int)(X); (i)++) {
    a[i][0] = 0;
    for (j = 1; j < Y; j++) a[i][j] = (a[i][j - 1] ^ r[i][j - 1]);
    if (i > 0) {
      int good = 0, bad = 0;
      for ((j) = 0; (j) < (int)(Y); (j)++)
        if (a[i][j] == (a[i - 1][j] ^ d[i - 1][j]))
          good++;
        else
          bad++;
      if (good < bad)
        for ((j) = 0; (j) < (int)(Y); (j)++) a[i][j] = (a[i][j] ^ 1);
    }
  }
}
void print(void) {
  int i, j;
  for ((i) = 0; (i) < (int)(X); (i)++)
    for ((j) = 0; (j) < (int)(Y); (j)++) {
      printf("%d", a[i][j] + 1);
      if (j == Y - 1)
        printf("\n");
      else
        printf(" ");
    }
}
int main(void) {
  int C, i, j;
  cin >> X >> Y >> C;
  for ((i) = 0; (i) < (int)(X); (i)++) {
    scanf("%s", buf);
    for ((j) = 0; (j) < (int)(Y - 1); (j)++)
      r[i][j] = ((buf[j] == 'E') ? 0 : 1);
    if (i == X - 1) break;
    scanf("%s", buf);
    for ((j) = 0; (j) < (int)(Y); (j)++) d[i][j] = ((buf[j] == 'E') ? 0 : 1);
  }
  int hor = X * (Y - 1);
  int ver = Y * (X - 1);
  if (C == 1) {
    int tmp = check();
    if (tmp * 4 >= (hor + ver) * 3) {
      cout << "YES" << endl;
      print();
    } else {
      cout << "NO" << endl;
    }
    return 0;
  }
  if (hor < ver)
    left_to_right();
  else
    top_to_down();
  int tmp2 = check();
  if (tmp2 * 4 >= (hor + ver) * 3) {
    cout << "YES" << endl;
    print();
  } else {
    cout << "warning!" << endl;
  }
  return 0;
}
