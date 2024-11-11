#include <bits/stdc++.h>
using namespace std;
int n;
double p[5][10001];
double pacum[5][10001];
double pgana[5][5][10001];
double egana[5][5][10001];
const int limite = 10000;
int main() {
  cout.setf(ios::fixed);
  cout.precision(15);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    for (int j = l; j <= r; j++) p[i][j] = 1.0 / (r - l + 1);
    for (int j = 1; j <= limite; j++) pacum[i][j] = pacum[i][j - 1] + p[i][j];
  }
  for (int i = 0; i < n; i++) {
    for (int iex = 0; iex < n; iex++) {
      if (i != iex) {
        for (int j = 1; j <= limite; j++) {
          double potros = 1;
          for (int iotro = 0; iotro < n; iotro++) {
            if (iotro != i and iotro != iex) {
              if (iotro < i)
                potros *= pacum[iotro][j - 1];
              else
                potros *= pacum[iotro][j];
            }
          }
          pgana[i][iex][j] = potros * p[i][j];
          egana[i][iex][j] = egana[i][iex][j - 1] + pgana[i][iex][j] * j;
        }
      }
    }
  }
  double e = 0;
  for (int iex = 0; iex < n; iex++) {
    for (int i = 0; i < n; i++) {
      for (int j = 1; j <= limite; j++) {
        if (i < iex) {
          e += egana[i][iex][j - 1] * p[iex][j];
        } else if (i > iex) {
          e += egana[i][iex][j] * p[iex][j];
        }
      }
    }
  }
  cout << e << endl;
}
