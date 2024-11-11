#include <bits/stdc++.h>
using namespace std;
void swap(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
}
int main() {
  int n, m;
  cin >> n >> m;
  int tingkat[m];
  for (int i = 0; i < m; i++) {
    cin >> tingkat[i];
  }
  int temp = m;
  for (int i = 0; i < m - 1; i++) {
    for (int j = 0; j < temp - 1; j++) {
      if (tingkat[j] > tingkat[j + 1]) {
        swap(tingkat[j], tingkat[j + 1]);
      }
    }
    temp--;
  }
  int terkecil = 2000000000;
  int selisih = -2;
  for (int i = 0; i + n - 1 < n; i++) {
    selisih = tingkat[i + n - 1] - tingkat[i];
    if (terkecil > selisih) {
      terkecil = selisih;
    }
  }
  cout << terkecil;
}
