#include <bits/stdc++.h>
using namespace std;
string i2s(int x) {
  stringstream ss;
  ss << x;
  return ss.str();
}
int s2i(string str) {
  istringstream ss(str);
  int nro;
  ss >> nro;
  return nro;
}
int n;
int NRO5(int nro) {
  int cnt = 0;
  while (nro % 5 == 0) {
    cnt++;
    nro /= 5;
  }
  return cnt;
}
int main() {
  int A[500005];
  map<int, vector<int> > mapa;
  map<int, vector<int> >::iterator it;
  for (int i = 1; i < 500005; i++) {
    A[i] = A[i - 1] + NRO5(i);
    mapa[A[i]].push_back(i);
  }
  scanf("%d\n", &n);
  if (mapa[n].size() == 0) {
    putchar('0');
    putchar('\n');
  } else {
    printf("%d\n", (int)mapa[n].size());
    for (int i = 0; i < mapa[n].size(); i++) {
      printf("%d%c", mapa[n][i], i == mapa[n].size() - 1 ? 10 : 32);
    }
  }
  return 0;
}
