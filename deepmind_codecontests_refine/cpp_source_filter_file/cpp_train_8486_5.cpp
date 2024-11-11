#include <bits/stdc++.h>
using namespace std;
void imprimirVector(vector<int> v) {
  if (!v.empty()) {
    int p = v.size();
    cout << "[";
    for (int i = 0; i < (int)(p - 1); i++) cout << v[i] << ",";
    cout << v[p - 1] << "]" << endl;
  } else
    cout << "[]" << endl;
}
int main() {
  int n, k;
  cin >> n >> k;
  long long counter = 0;
  vector<vector<int> > g(n, vector<int>(n));
  if (k == 1) {
    for (int i = 0; i < (int)(n); i++) {
      for (int j = 0; j < (int)(n); j++) g[i][j] = i * n + j + 1;
      counter += i * n + 1;
    }
  } else {
    for (int j = 0; j < (int)(k - 1); j++)
      for (int i = 0; i < (int)(n); i++) g[i][j] = i + 1 + j * n;
    int next = g[n - 1][k - 2];
    next++;
    for (int i = 0; i < (int)(n); i++) {
      counter += next;
      for (int j = (k - 1); j < (int)(n); j++) g[i][j] = next++;
    }
  }
  cout << counter;
  for (int i = 0; i < (int)(n); i++) {
    if (i) printf("\n");
    for (int j = 0; j < (int)(n); j++) {
      if (j) printf(" ");
      printf("%d", g[i][j]);
    }
  }
  printf("\n");
  return 0;
}
