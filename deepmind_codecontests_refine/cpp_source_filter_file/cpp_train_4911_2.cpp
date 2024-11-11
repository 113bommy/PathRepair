#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0;
  cin >> n;
  int arr[n * 2 + 1][n * 2 + 1], mid = n * 2 + 1, aux = n;
  memset(arr, -1, sizeof(arr));
  int inicio = 0;
  for (int i = n; i >= 0; i--) {
    int cambio = 0;
    bool b = true;
    for (int j = inicio; j < mid; j++) {
      arr[i][j] = cambio;
      if (cambio == aux) b = false;
      if (b)
        cambio++;
      else
        cambio--;
    }
    mid--;
    aux--;
    inicio++;
  }
  int medio2 = n;
  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < n * 2 + 1; j++) {
      if (arr[i][j] == 0 && j == medio2) {
        cout << arr[i][j];
        break;
      } else if (arr[i][j] != -1)
        cout << arr[i][j] << " ";
      else
        cout << "  ";
    }
    cout << endl;
    medio2++;
  }
  medio2--;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < n * 2 + 1; j++) {
      if (arr[i][j] == 0 && j == medio2) {
        cout << arr[i][j];
        break;
      } else if (arr[i][j] != -1)
        cout << arr[i][j] << " ";
      else
        cout << "  ";
    }
    cout << endl;
    medio2--;
  }
  return 0;
}
