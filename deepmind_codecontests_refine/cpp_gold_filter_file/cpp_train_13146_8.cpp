#include <bits/stdc++.h>
using namespace std;
long long valor(int A, int B, int C, int n) {
  A = (long long)((long long)A + (long long)1),
  B = (long long)((long long)B + (long long)2),
  C = (long long)((long long)C + (long long)2);
  return (long long)((long long)A * (long long)B * (long long)C - (long long)n);
}
int main() {
  int n, A, B, C;
  long long r, menor, mayor;
  while (cin >> n) {
    menor = (long long)(1e15), mayor = -1;
    for (A = 1; A <= n / A; A++) {
      if (n % A == 0) {
        for (B = 1; B <= (n / A) / B; B++) {
          if ((n / A) % B == 0) {
            C = (n / A) / B;
            r = valor(A, B, C, n), menor = min(menor, r), mayor = max(mayor, r);
            r = valor(A, C, B, n), menor = min(menor, r), mayor = max(mayor, r);
            r = valor(B, A, C, n), menor = min(menor, r), mayor = max(mayor, r);
            r = valor(B, C, A, n), menor = min(menor, r), mayor = max(mayor, r);
            r = valor(C, A, B, n), menor = min(menor, r), mayor = max(mayor, r);
            r = valor(C, B, A, n), menor = min(menor, r), mayor = max(mayor, r);
          }
        }
      }
    }
    cout << menor << " " << mayor << endl;
  }
  return 0;
}
