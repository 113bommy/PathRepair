#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  cout.tie(0);
  long long n, m[200001], valore, somma = 0, M, massimo[200001] = {0};
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> m[i];
    for (int j = 0; j < m[i]; j++) {
      cin >> valore;
      massimo[i] = max(massimo[i], valore);
    }
  }
  M = *max_element(massimo, massimo + n);
  for (int i = 0; i < n; i++) somma += m[i] * (M - massimo[i]);
  cout << somma;
  return 0;
}
