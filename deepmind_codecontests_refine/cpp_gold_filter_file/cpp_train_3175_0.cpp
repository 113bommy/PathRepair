#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  int a[N], L[N];
  int i;
  int str[N][20];
  int mins = 20;
  int mind = -1;
  for (i = 0; i < N; i++) {
    cin >> a[i];
    int t = a[i];
    L[i] = 0;
    while (t >= 1) {
      str[i][L[i]] = t % 2;
      t = int(t / 2);
      L[i] = L[i] + 1;
    }
    if (L[i] < mins) {
      mins = L[i];
      mind = i;
    }
  }
  mins = 2147483647;
  int nows;
  int compare_str[20];
  int add_ite;
  for (int Len = 1; Len < 20; Len++) {
    for (int del = 0; del < L[mind]; del++) {
      if (L[mind] - del > Len) continue;
      for (int t = 0; t < Len - (L[mind] - del); t++) compare_str[t] = 0;
      for (int t = 0; t < L[mind] - del; t++)
        compare_str[t + Len - (L[mind] - del)] = str[mind][t + del];
      nows = 0;
      for (i = 0; i < N; i++) {
        int id_i = L[i] - 1;
        int id_compare = Len - 1;
        while (id_i >= 0 && id_compare >= 0 &&
               compare_str[id_compare] == str[i][id_i]) {
          id_i--;
          id_compare--;
        }
        add_ite = id_i + id_compare + 2;
        if (id_i >= 0 && id_compare >= 0 && compare_str[id_compare] == 1)
          nows = 2147483647;
        if (id_compare >= 0 && compare_str[id_compare] == 0) {
          while (id_compare >= 0) {
            if (compare_str[id_compare] == 1) {
              nows = 2147483647;
              break;
            }
            id_compare--;
          }
        }
        if (nows == 2147483647) break;
        nows = nows + add_ite;
      }
      if (nows < mins) {
        mins = nows;
      }
    }
  }
  cout << mins;
  return 0;
}
