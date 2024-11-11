#include <bits/stdc++.h>
using namespace std;
vector<int> luz;
vector<int> actual;
int calc(int n) {
  if (n == 1) return 0;
  return luz[n - 2] + calc(n / 2);
}
int solve(int ini, int fin) {
  if (ini == fin) {
    return actual[ini];
  }
  int minimo = 1e9;
  for (int i = ini; i < fin + 1; i++) {
    minimo = min(minimo, actual[i]);
  }
  for (int i = ini; i < fin + 1; i++) {
    actual[i] -= minimo;
  }
  int valores = fin - ini + 1;
  return minimo + solve(ini, ini + valores / 2 - 1) +
         solve(ini + valores / 2, fin);
}
int main() {
  int n;
  cin >> n;
  int tope = pow(2, n + 1) - 2;
  for (int i = 0; i < tope; i++) {
    int a;
    cin >> a;
    luz.push_back(a);
  }
  int ini = pow(2, n);
  int fin = pow(2, n + 1) - 1;
  for (int i = ini; i < fin + 1; i++) {
    int val = calc(i);
    actual.push_back(val);
  }
  int maxi = 0;
  for (int i = 0; i < actual.size(); i++) {
    maxi = max(actual[i], maxi);
  }
  for (int i = 0; i < actual.size(); i++) {
    actual[i] = (maxi - actual[i]);
  }
  int suma = solve(0, actual.size() / 2 - 1) +
             solve(actual.size() / 2, actual.size() - 1);
  cout << suma << endl;
  return 0;
}
