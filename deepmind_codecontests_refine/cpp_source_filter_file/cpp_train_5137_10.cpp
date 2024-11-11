#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const unsigned long long base = 311;
unsigned long long TH[maxn][3], L[3], P[maxn];
int Sol, lona, lonb;
void calc_Hash(string& a, int id) {
  int lon = L[id];
  for (int i = (1); i <= (lon); i += (1)) {
    TH[i][id] = TH[i - 1][id] * base + (unsigned long long)(a[i] - '0');
  }
  return;
}
void calc_pot(int N) {
  P[0] = 1;
  for (int i = (1); i <= (N); i += (1)) {
    P[i] = P[i - 1] * base;
  }
  return;
}
bool completa(int tam, int id) {
  int lon = L[id];
  unsigned long long H = TH[tam][id];
  bool flag = true;
  for (int i = (tam); i <= (lon); i += (tam)) {
    if (TH[i][id] - TH[i - tam][id] * P[tam] != H) {
      flag = false;
      break;
    }
  }
  return flag;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string A, B;
  cin >> A >> B;
  lona = A.size();
  lonb = B.size();
  L[1] = lona;
  L[2] = lonb;
  A = " " + A;
  B = " " + B;
  calc_pot(((lona) > (lonb) ? (lona) : (lonb)));
  calc_Hash(A, 1);
  calc_Hash(B, 2);
  int l = ((lona) < (lonb) ? (lona) : (lonb));
  for (int i = (1); i <= (l); i += (1)) {
    if (!(lona % i) && !(lonb % i)) {
      if (completa(i, 1) && completa(i, 2)) {
        Sol++;
      }
    }
  }
  cout << Sol << "\n";
  return 0;
}
