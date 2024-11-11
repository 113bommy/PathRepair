#include <bits/stdc++.h>
using namespace std;
int T[400010], P[400010];
int b[400010], n, m;
int counter = 0;
void kmpPreprocess() {
  int i = 0, j = -1;
  b[0] = -1;
  while (i < m) {
    while (j >= 0 && P[i] != P[j]) j = b[j];
    i++;
    j++;
    b[i] = j;
  }
}
void kmpSearch() {
  int i = 0, j = 0;
  while (i < n) {
    while (j >= 0 && T[i] != P[j]) j = b[j];
    i++;
    j++;
    if (j == m) {
      counter++;
      j = b[j];
    }
  }
}
int main() {
  cin >> n >> m;
  n--;
  m--;
  if (m == 0) {
    cout << (n + 1);
    return 0;
  }
  int last, temp;
  cin >> last;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    T[i] = temp - last;
    last = temp;
  }
  cin >> last;
  for (int i = 0; i < m; i++) {
    cin >> temp;
    P[i] = temp - last;
    last = temp;
  }
  kmpPreprocess();
  kmpSearch();
  cout << counter;
  return 0;
}
