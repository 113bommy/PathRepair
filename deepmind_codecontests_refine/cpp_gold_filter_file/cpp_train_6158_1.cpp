#include <bits/stdc++.h>
using namespace std;
template <typename T>
string tos(T a) {
  stringstream ss;
  string ret;
  ss << a;
  ss >> ret;
  return ret;
}
void read(int &_a) { int temp = scanf("%d", &_a); }
void read(int &_a, int &_b) { int temp = scanf("%d %d", &_a, &_b); }
void read(int &_a, int &_b, int &_c) {
  int temp = scanf("%d %d %d", &_a, &_b, &_c);
}
const int SZ = 2e5 + 7;
int N, M, Q;
int P[SZ], A[SZ], T[SZ], TX[SZ][20];
int PX[SZ], AX[SZ], MXR[SZ];
int getp(int u, int n) {
  int lg = 1;
  while ((1 << lg) <= n) lg++;
  lg--;
  for (int i = lg; i >= 0; i--) {
    if (u == -1) break;
    if ((1 << i) <= n) {
      n -= (1 << i);
      u = TX[u][i];
    }
  }
  return u;
}
int main() {
  while (cin >> N >> M >> Q) {
    memset(T, -1, sizeof T);
    ;
    memset(TX, -1, sizeof TX);
    ;
    memset(AX, -1, sizeof AX);
    ;
    for (int(x) = (0); (x) < (N); (x)++) {
      read(P[x]);
      PX[P[x]] = x;
    }
    for (int(x) = (0); (x) < (M); (x)++) {
      read(A[x]);
      int li = PX[A[x]];
      li = (li - 1 + N) % N;
      int pv = P[li];
      if (AX[pv] != -1) T[x] = AX[pv];
      AX[A[x]] = x;
    }
    for (int(x) = (0); (x) < (M); (x)++) TX[x][0] = T[x];
    for (int j = 1; (1 << j) <= M; j++) {
      for (int(i) = (0); (i) < (M); (i)++) {
        if (TX[i][j - 1] != -1) {
          TX[i][j] = TX[TX[i][j - 1]][j - 1];
        }
      }
    }
    int mx = -1;
    for (int(x) = (0); (x) < (M); (x)++) {
      int lf = getp(x, N - 1);
      mx = max(mx, lf);
      MXR[x] = mx;
    }
    string ans = "";
    int la, lb;
    for (int(q) = (0); (q) < (Q); (q)++) {
      read(la, lb);
      la--;
      lb--;
      int lf = MXR[lb];
      if (lf >= la)
        ans += "1";
      else
        ans += "0";
    }
    cout << ans << endl;
  }
  return 0;
}
