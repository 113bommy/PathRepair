#include <bits/stdc++.h>
using namespace std;
long long n, sumaReal, sumaMaxima, arr[200003], sumaMinima;
int main() {
  scanf("%I64d %I64d", &n, &sumaReal);
  sumaMinima = n - 1;
  for (int i = 0; i < n; i++) {
    scanf("%I64d", &arr[i]);
    sumaMaxima += arr[i];
  }
  for (int i = 0; i < n; i++) {
    sumaMaxima -= arr[i];
    if (sumaMaxima >= sumaReal) {
      long long val = sumaReal - sumaMinima;
      if (val < arr[i])
        cout << (arr[i] - val) << " ";
      else
        printf("0 ");
    } else {
      long long faltan = sumaReal - sumaMaxima - 1;
      if (arr[i] + sumaMinima > sumaReal)
        faltan += arr[i] - sumaReal + sumaMinima;
      cout << faltan << " ";
    }
    sumaMaxima += arr[i];
  }
}
