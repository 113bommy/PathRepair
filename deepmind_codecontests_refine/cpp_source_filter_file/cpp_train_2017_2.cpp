#include <bits/stdc++.h>
using namespace std;
int N;
int lin[1010], col[1010], a[1010][1010], wl[1010], wc[1010];
int lg;
struct solution {
  int Q, first, second;
  solution() {}
  solution(int _Q, int _first, int _second) {
    this->Q = _Q;
    this->first = _first;
    this->second = _second;
  }
  inline void write() {
    cout << this->Q << ' ' << this->first << ' ' << this->second << '\n';
  }
} A[10010];
int main() {
  cin >> N;
  for (int i = 1; i < N; i++) {
    int x, y;
    cin >> x >> y;
    lin[x]++;
    col[y]++;
    a[x][y]++;
    wl[i] = i, wc[i] = i;
  }
  wl[N] = N, wc[N] = N;
  for (int i = N; i > 1; i--) {
    int aux;
    aux = 0;
    for (int j = 1; j < i; j++) {
      if (col[wc[j]] == 0) {
        aux = j;
        break;
      }
    }
    if (aux) {
      swap(wc[i], wc[aux]);
      A[++lg] = solution(2, i, aux);
    }
    aux = 0;
    for (int j = 1; j < i; j++) {
      if (lin[wl[j]]) {
        aux = j;
      }
    }
    if (aux) {
      swap(wl[i], wl[aux]);
      A[++lg] = solution(1, i, aux);
      for (int j = 1; j <= i; j++) {
        col[j] = col[j] - a[wl[i]][wc[j]];
      }
    }
  }
  cout << lg << '\n';
  for (int i = 1; i <= lg; A[i].write(), i++)
    ;
  return 0;
}
