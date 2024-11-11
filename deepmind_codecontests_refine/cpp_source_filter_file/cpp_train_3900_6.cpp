#include <bits/stdc++.h>
using namespace std;
int mat[2005][2005];
long long int der[2005][2005];
long long int izq[2005][2005];
int n;
void fillder() {
  int a, b;
  for (int j = 1; j < n + 1; j++) {
    a = 1, b = j;
    long long int aux = 0ll;
    while (a <= n && b <= n) {
      aux += mat[a][b];
      a++;
      b++;
    }
    a = 1, b = j;
    while (a <= n && b <= n) {
      der[a][b] = aux;
      a++;
      b++;
    }
  }
  for (int i = 2; i < n + 1; i++) {
    a = i, b = 1;
    long long int aux = 0ll;
    while (a <= n && b <= n) {
      aux += mat[a][b];
      a++;
      b++;
    }
    a = i, b = 1;
    while (a <= n && b <= n) {
      der[a][b] = aux;
      a++;
      b++;
    }
  }
}
void fillizq() {
  int a, b;
  for (int j = n; j >= 1; j--) {
    a = 1, b = j;
    long long int aux = 0;
    while (a <= n && b >= 1) {
      aux += mat[a][b];
      a++;
      b--;
    }
    a = 1, b = j;
    while (a <= n && b >= 1) {
      izq[a][b] = aux;
      a++;
      b--;
    }
  }
  for (int i = 2; i <= n; i++) {
    a = i;
    b = n;
    long long int aux = 0;
    while (a <= n && b >= 1) {
      aux += mat[a][b];
      a++;
      b--;
    }
    a = i;
    b = n;
    while (a <= n && b >= 1) {
      izq[a][b] = aux;
      a++;
      b--;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i < n + 1; i++)
    for (int j = 1; j < n + 1; j++) cin >> mat[i][j];
  fillder();
  fillizq();
  long long int uno = 0, dos = 0;
  int unox = -1, unoy = -1, dosx = -1, dosy = -1;
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < n + 1; j++) {
      long long int res = izq[i][j] + der[i][j] - mat[i][j];
      if ((i + j) % 2 == 0) {
        if (res > uno) {
          uno = res;
          unox = i;
          unoy = j;
        }
      } else {
        if (res > dos) {
          dos = res;
          dosx = i;
          dosy = j;
        }
      }
    }
  }
  cout << uno + dos << '\n';
  cout << unox << " " << unoy << " ";
  cout << dosx << " " << dosy;
  return 0;
}
