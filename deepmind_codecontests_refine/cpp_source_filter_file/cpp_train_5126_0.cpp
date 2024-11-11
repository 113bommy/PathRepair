#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    vector<int> numeros(101, 0);
    int n, x;
    cin >> n >> x;
    while (n--) {
      int aux;
      cin >> aux;
      numeros[aux] = 1;
    }
    for (int i = 1; i <= x + 1; i++) {
      if (numeros[i]) x++;
    }
    cout << x << '\n';
  }
}
