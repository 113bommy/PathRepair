#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n;
  cin >> a >> b;
  if (n > a * b)
    cout << "-1";
  else {
    int **c = new int *[a];
    for (int i = 0; i < a; i++) {
      c[i] = new int[b];
      for (int j = 0; j < b; j++) c[i][j] = 0;
    }
    if (b % 2 == 1) {
      for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
          if (i * b + j + 1 <= n) c[i][j] = i * b + j + 1;
    } else {
      for (int i = 0; i < a; i++)
        if (i % 2 == 0) {
          for (int j = 0; j < b; j++)
            if (i * b + j + 1 <= n) c[i][j] = i * b + j + 1;
        } else {
          for (int j = b - 1; j >= 0; j--)
            if (i * b + b - j <= n) c[i][j] = i * b + b - j;
        }
    }
    for (int i = 0; i < a; i++) {
      for (int j = 0; j < b; j++) cout << c[i][j] << ' ';
      cout << endl;
    }
  }
  return 0;
}
