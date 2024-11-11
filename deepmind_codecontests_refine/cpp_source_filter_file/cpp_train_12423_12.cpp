#include <bits/stdc++.h>
using namespace std;
int i, d[100000], a, d2[100000], b, w[100000], j;
char k[100000], k2[100000];
void merge(int bas, int orta, int son) {
  int i = bas, j = orta, k = bas;
  while (i < orta && j < son) w[k++] = (d2[i] > d2[j]) ? d2[i++] : d2[j++];
  while (i < orta) w[k++] = d2[i++];
  while (j < son) w[k++] = d2[j++];
  for (i = bas; i < son; i++) d2[i] = w[i];
}
void mergesort(int bas, int son) {
  if (bas + 1 == son) return;
  int orta = (bas + son) / 2;
  mergesort(bas, orta);
  mergesort(orta, son);
  merge(bas, orta, son);
}
int main() {
  cin >> k;
  a = strlen(k);
  for (i = 0; i < a; i++) {
    if (k[i] == '0')
      d[i + 1] = 0;
    else
      d[i + 1] = k[i] - '0';
  }
  cin >> k2;
  b = strlen(k2);
  for (i = 0; i < b; i++) d2[i + 1] = k2[i] - '0';
  mergesort(1, b + 1);
  int t = 1;
  for (i = 1; i <= a; i++) {
    if (d[i] < d2[t]) {
      d[i] = d2[t];
      t++;
    }
  }
  for (i = 1; i <= a; i++) printf("%d", d[i]);
  return 0;
}
