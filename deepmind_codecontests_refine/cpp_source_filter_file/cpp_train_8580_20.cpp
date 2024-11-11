#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  int mini = INT_MAX;
  vector<int> w(n);
  for (int j = 0; j <= 100001; j++) {
    vector<int> aux(n);
    aux[0] = j;
    for (int i = 1; i < n; i++) {
      aux[i] = aux[i - 1] + k;
    }
    int cant = 0;
    for (int i = 0; i < n; i++) {
      if (v[i] != aux[i]) cant++;
    }
    if (cant < mini) {
      mini = cant;
      w = aux;
    }
  }
  cout << mini << endl;
  for (int i = 0; i < ((int)w.size()); i++) {
    if (w[i] < v[i]) {
      cout << "- " << (i + 1) << " " << abs(w[i] - v[i]) << endl;
    } else if (w[i] > v[i]) {
      cout << "+ " << (i + 1) << " " << abs(w[i] - v[i]) << endl;
    }
  }
  return 0;
}
