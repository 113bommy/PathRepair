#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, min = 10000, max = 0;
  set<int> *dej;
  cin >> n >> m;
  dej = new set<int>[m];
  for (int i = 0; i < m; i++) {
    int bottom, top;
    cin >> bottom >> top;
    if (bottom < min) min = bottom;
    if (top > max) max = top;
    for (int j = bottom; j <= top; j++) dej[i].insert(j);
  }
  for (int i = min; i <= max; i++) {
    int count = 0;
    for (int j = 0; j < m; j++) {
      if (dej[j].find(i) != dej[j].end()) count++;
    }
    if (count != 1) {
      cout << i << " " << count;
      return 0;
    }
  }
  cout << "OK";
  return 0;
}
