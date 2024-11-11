#include <bits/stdc++.h>
using namespace std;
struct edge {
  unsigned vOrig, vDest, w;
  edge(unsigned _vOrig, unsigned _vDest, unsigned _w)
      : vOrig(_vOrig), vDest(_vDest), w(_w){};
};
const double errorMin = 1e-9;
unsigned N, M;
vector<unsigned> V;
vector<edge> E;
double dens(edge &e) {
  if (e.w == 0) {
    return 0;
  }
  return (double)(V[e.vOrig] + V[e.vDest]) / (double)e.w;
}
void crearVectores() {
  V = vector<unsigned>(N);
  E = vector<edge>(M, edge(0, 0, 0));
}
int main() {
  unsigned v1, v2, w, n, m;
  double densidad;
  double max = 0;
  cout << setprecision(20);
  cin >> N;
  cin >> M;
  crearVectores();
  for (n = 0; n < N; n++) {
    cin >> w;
    V[n] = w;
  }
  for (m = 0; m < M; m++) {
    cin >> v1;
    cin >> v2;
    cin >> w;
    v1--;
    v2--;
    E[m].vOrig = v1;
    E[m].vDest = v2;
    E[m].w = w;
    densidad = dens(E[m]);
    if (densidad > max) {
      max = densidad;
    }
  }
  cout << max << endl;
  return 0;
}
