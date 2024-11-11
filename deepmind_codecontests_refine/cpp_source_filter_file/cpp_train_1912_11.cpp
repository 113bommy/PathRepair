#include <bits/stdc++.h>
using namespace std;
int ma[105][10005];
int sol[105][105];
int arr[105];
int main() {
  int n, m;
  cin >> n >> m;
  string cad;
  for (int i = 0; i < n; i++) {
    int aux = 0;
    cin >> cad;
    for (int j = 0; j < m; j++) {
      ma[i][j] = cad[j] - '0';
      if (ma[i][j] == 1) {
        arr[i] = j;
        aux++;
      }
    }
    if (aux == 0) {
      cout << "-1" << endl;
      return 0;
    }
  }
  int suma = 0, cont = 0;
  for (int i = 0; i < n; i++) {
    bool flag = false;
    for (int j = arr[i]; j < m; j++) {
      if (j == arr[i] && flag) break;
      if (j == arr[i] && !flag) {
        flag = true;
      }
      if (ma[i][j] == 1) cont = 0;
      sol[i][j] = cont;
      cont++;
      if (j + 1 == m) j = -1;
    }
    flag = false;
    cont = 0;
    for (int j = arr[i]; j >= 0; j--) {
      if (j == arr[i] && flag) break;
      if (j == arr[i] && !flag) {
        flag = true;
      }
      if (ma[i][j] == 1) cont = 0;
      sol[i][j] = min(cont, sol[i][j]);
      cont++;
      if (j == 0) j = m;
    }
  }
  int men = -5;
  for (int j = 0; j < m; j++) {
    int suma = 0;
    for (int i = 0; i < n; i++) {
      suma += sol[i][j];
    }
    if (suma < men || men == -5) {
      men = suma;
    }
  }
  cout << men << endl;
}
