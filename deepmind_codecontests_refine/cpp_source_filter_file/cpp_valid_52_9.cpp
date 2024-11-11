#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<double> vec;
    for (int i = 0; i < n; i++) {
      int aux;
      cin >> aux;
      vec.push_back(aux);
    }
    sort(vec.begin(), vec.end());
    double aux = 0;
    for (int i = 0; i < n - 1; i++) {
      aux += vec[i];
    }
    aux /= n - 1;
    cout << fixed << setprecision(9);
    cout << (1.0 * vec[n - 1]) + aux;
  }
}
