#include <bits/stdc++.h>
using namespace std;
vector<long long> Tx, Ty;
vector<long long> Lx, Ly;
int lx, sizex;
int ly, sizey;
void Stworzx(int n) {
  int p = 1;
  while (p < n) p *= 2;
  lx = p;
  sizex = 2 * p - 1;
  for (int i = 0; i <= sizex; ++i) {
    Tx.push_back(0);
    Lx.push_back(0);
  }
}
void Stworzy(int n) {
  int p = 1;
  while (p < n) p *= 2;
  ly = p;
  sizey = 2 * p - 1;
  for (int i = 0; i <= sizey; ++i) {
    Ty.push_back(0);
    Ly.push_back(0);
  }
}
void Propagujx(int akt, long long L, long long P) {
  Tx[2 * akt] += Lx[akt] * ((P - L + 1) / 2);
  Tx[2 * akt + 1] += Lx[akt] * ((P - L + 1) / 2);
  Lx[2 * akt] += Lx[akt];
  Lx[2 * akt + 1] += Lx[akt];
  Lx[akt] = 0;
}
void Propagujy(int akt, long long L, long long P) {
  Ty[2 * akt] += Ly[akt] * ((P - L + 1) / 2);
  Ty[2 * akt + 1] += Ly[akt] * ((P - L + 1) / 2);
  Ly[2 * akt] += Ly[akt];
  Ly[2 * akt + 1] += Ly[akt];
  Ly[akt] = 0;
}
void Dodajx(int akt, long long L, long long P, long long l, long long p,
            long long x) {
  if (l > p) return;
  if (l == L && p == P) {
    Tx[akt] += (P - L + 1) * x;
    Lx[akt] += x;
  } else {
    Propagujx(akt, L, P);
    long long S = (L + P) / 2;
    Dodajx(2 * akt, L, S, l, min(p, S), x);
    Dodajx(2 * akt + 1, S + 1, P, max(l, S + 1), p, x);
    Tx[akt] = Tx[2 * akt] + Tx[2 * akt + 1];
  }
}
void Dodajy(int akt, long long L, long long P, long long l, long long p,
            long long x) {
  if (l > p) return;
  if (l == L && p == P) {
    Ty[akt] += (P - L + 1) * x;
    Ly[akt] += x;
  } else {
    Propagujy(akt, L, P);
    long long S = (L + P) / 2;
    Dodajy(2 * akt, L, S, l, min(p, S), x);
    Dodajy(2 * akt + 1, S + 1, P, max(l, S + 1), p, x);
    Ty[akt] = Ty[2 * akt] + Ty[2 * akt + 1];
  }
}
long long Sumax(int akt, long long L, long long P, long long l, long long p) {
  if (l > p) return 0;
  if (l == L && p == P) return Tx[akt];
  Propagujx(akt, L, P);
  long long S = (L + P) / 2;
  return Sumax(2 * akt, L, S, l, min(p, S)) +
         Sumax(2 * akt + 1, S + 1, P, max(l, S + 1), p);
}
long long Sumay(int akt, long long L, long long P, long long l, long long p) {
  if (l > p) return 0;
  if (l == L && p == P) return Ty[akt];
  Propagujy(akt, L, P);
  long long S = (L + P) / 2;
  return Sumay(2 * akt, L, S, l, min(p, S)) +
         Sumay(2 * akt + 1, S + 1, P, max(l, S + 1), p);
}
int main() {
  int n, m, w;
  scanf("%d %d %d", &n, &m, &w);
  Stworzx(n);
  Stworzy(m);
  long long wsz = 0;
  for (int i = 0; i < w; ++i) {
    int op, x1, y1, x2, y2;
    scanf("%d %d %d %d %d", &op, &x1, &y1, &x2, &y2);
    --x1;
    --y1;
    --x2;
    --y2;
    if (op == 0) {
      long long v;
      scanf("%I64d", &v);
      Dodajx(1, 0, (sizex + 1) / 2 - 1, x1, x2, (y2 - y1 + 1) * v);
      Dodajy(1, 0, (sizey + 1) / 2 - 1, y1, y2, (x2 - x1 + 1) * v);
      wsz += (x2 - x1 + 1) * (y2 - y1 + 1) * v;
    } else
      printf("%I64d\n", Sumax(1, 0, (sizex + 1) / 2 - 1, x1, x2) +
                            Sumay(1, 0, (sizey + 1) / 2 - 1, y1, y2) - wsz);
  }
  return 0;
}
