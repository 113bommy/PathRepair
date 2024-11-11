#include <bits/stdc++.h>
using namespace std;
void pout(bool *b, int N) {
  int x, y;
  bool *pb = b;
  cout << endl;
  for (x = 0; x < N; ++x) {
    for (y = 0; y < N; ++y, ++pb) {
      cout << (*pb ? 1 : 0);
    }
    cout << endl;
  }
  cout << endl;
  return;
}
int main() {
  int N;
  cin >> N;
  int N2 = N * N;
  int Np1 = N + 1;
  bool *b = new bool[N2 + N * 4];
  bool *T = b + N2;
  bool *R = T + N;
  bool *B = R + N;
  bool *L = B + N;
  bool *H;
  bool *V;
  bool *pb;
  bool *pbXY;
  int x, y;
  int flips;
  memset(b, 0, (N2 + N * 4) * (sizeof b[0]));
  pb = b;
  for (int i = 0; i < N; ++i) {
    char c2k[2048];
    cin.getline(c2k, 2048);
    if (cin.gcount() < N) cin.getline(c2k, 2048);
    char *pC = c2k;
    for (int j = 0; j < N; ++j, ++pb) {
      *pb = *(pC++) == '1';
    }
  }
  if (N < 2) {
    cout << (N && b[0] ? 1 : 0) << endl;
    return 0;
  }
  flips = 0;
  for (int diagN = N; --diagN;) {
    for (int diag = -diagN; diag <= (2 * diagN); diag += 2 * diagN) {
      H = diag < 0 ? L : R;
      V = diag < 0 ? B : T;
      x = max(0, -diag);
      y = max(0, diag);
      for (pbXY = b + ((x)*N) + (y); x < N && y < N; ++x, ++y, pbXY += Np1) {
        if ((*pbXY ^ H[x] ^ V[y])) {
          ++flips;
          H[x] = !H[x];
          V[y] = !V[y];
        }
      }
    }
  }
  for ((pb = b), x = 0; x < N; ++x, pb += Np1)
    flips += (*pb ^ T[x] ^ B[x] ^ L[x] ^ R[x]) ? 1 : 0;
  cout << flips << endl;
  return 0;
}
