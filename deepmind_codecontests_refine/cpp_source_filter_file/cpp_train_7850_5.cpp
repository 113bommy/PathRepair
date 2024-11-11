#include <bits/stdc++.h>
using namespace std;
int listas[15][15];
bool matriz[1003][1003];
vector<vector<int> > Lista;
vector<int> inicio(1, 1), fin(1, 2);
int sig = 3;
void inserta(int e) {
  vector<int> v;
  for (int i = 0; i < e; ++i) v.push_back(sig++);
  Lista.push_back(v);
}
int main() {
  int n, c, i = 0;
  cin >> n;
  c = n;
  for (int i1 = 0; i1 < 11; ++i1)
    for (int j1 = 0; j1 < 11; ++j1) listas[i1][j1] = 1;
  while (c) {
    listas[i][0] = c % 10;
    c /= 10;
    for (int i1 = 0; i1 < i; ++i1) listas[i][i1] = 10;
    ++i;
  }
  for (int j = 0; j < i; ++j) {
    Lista.clear();
    Lista.push_back(inicio);
    for (int k = 0; k < i; ++k) {
      inserta(listas[j][k]);
    }
    Lista.push_back(fin);
    for (int i = 0; i < Lista.size() - 1; ++i) {
      for (auto& e1 : Lista[i])
        for (auto& e2 : Lista[i + 1]) matriz[e1][e2] = matriz[e2][e1] = 1;
    }
  }
  printf("%d\n", sig - 1);
  for (int i = 1; i < sig; ++i, printf("\n"))
    for (int j = 1; j < sig; ++j)
      if (matriz[i][j])
        printf("Y");
      else
        printf("N");
  return 0;
}
