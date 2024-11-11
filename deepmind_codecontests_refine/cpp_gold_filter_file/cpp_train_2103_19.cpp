#include <bits/stdc++.h>
int main() {
  int casos, nConferencias, nClases, bConferencias, lClases, caja;
  scanf("%d", &casos);
  for (int i = 0; i < casos; i++) {
    int suma = 0, boli = 1, lapiz = 1;
    scanf("%d%d%d%d%d", &nConferencias, &nClases, &bConferencias, &lClases,
          &caja);
    while (bConferencias < nConferencias) {
      nConferencias -= bConferencias;
      boli++;
    }
    while (lClases < nClases) {
      nClases -= lClases;
      lapiz++;
    }
    suma = boli + lapiz;
    if (suma > caja) {
      printf("-1\n");
    } else {
      printf("%d %d\n", boli, lapiz);
    }
  }
  return 0;
}
