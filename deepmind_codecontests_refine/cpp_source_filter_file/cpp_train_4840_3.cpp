#include <bits/stdc++.h>
using namespace std;
const int N = 10e5;
const int oo = INT_MAX;
const int Noo = INT_MIN;
int mat[105][105];
bool car[100];
void TT(int n) {
  int x = 0;
  car[0] = 0;
  for (int i = 0; i < (int)n; i++) {
    for (int j = 0; j < (int)n; j++) {
      if (mat[i][j] == 1 && car[i + 1] == 1) {
        ++x;
        car[i + 1] = 0;
      }
      if (mat[i][j] == 2 && car[j + 1] == 1) {
        ++x;
        car[j + 1] = 0;
      }
      if (mat[i][j] == 3 && car[i + 1] == 1) {
        ++x;
        car[i + 1] = 0;
      }
      if (mat[i][j] == 3 && car[j + 1] == 1) {
        ++x;
        car[j + 1] = 0;
      }
    }
  }
  cout << n - x << endl;
  for (int i = 0; i < (int)n; i++) {
    if (car[i] == 1) cout << i << " ";
  }
}
int main() {
  ios::sync_with_stdio(false);
  memset(car, 1, sizeof(car));
  int n;
  cin >> n;
  for (int i = 0; i < (int)n; i++) {
    for (int j = 0; j < (int)n; j++) {
      cin >> mat[i][j];
    }
  }
  TT(n);
}
