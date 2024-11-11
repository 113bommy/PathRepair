#include <bits/stdc++.h>
using namespace std;
char Tablero[9][9];
int UltimoEnW, UltimoEnB;
int MovimientosW[32];
int MovimientosB[32];
int main() {
  for (int i = 1; i < 9; i++) {
    for (int j = 1; j < 9; j++) {
      cin >> Tablero[i][j];
    }
  }
  for (int i = 1; i <= 8; i++) {
    for (int j = 1; j <= 8; j++) {
      if (Tablero[i][j] == 'W' || Tablero[i][j] == 'B') {
        int PiezasDelante = 0;
        int CasillerosDelante = 0;
        if (Tablero[i][j] == 'W') {
          for (int k = i - 1; k >= 1; k--) {
            if (Tablero[k][j] == 'W' || Tablero[k][j] == 'B') PiezasDelante++;
            CasillerosDelante++;
          }
          if (PiezasDelante == 0) {
            MovimientosW[UltimoEnW] = CasillerosDelante;
            UltimoEnW++;
          }
        } else if (Tablero[i][j] == 'B') {
          for (int k = i + 1; k <= 8; k++) {
            if (Tablero[k][j] == 'W' || Tablero[k][j] == 'B') PiezasDelante++;
            CasillerosDelante++;
          }
          if (PiezasDelante == 0) {
            MovimientosB[UltimoEnB] = CasillerosDelante;
            UltimoEnB++;
          }
        }
      }
    }
  }
  sort(MovimientosW, MovimientosW + UltimoEnW);
  sort(MovimientosB, MovimientosB + UltimoEnB);
  if (MovimientosW[0] < MovimientosB[0] || MovimientosW[0] == MovimientosB[0])
    cout << "A";
  else
    cout << "B";
}
