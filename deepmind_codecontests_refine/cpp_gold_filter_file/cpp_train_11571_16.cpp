#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, v;
  cin >> n >> v;
  int cont = 0;
  cont += min(v, n - 1);
  int custo = min(v, n - 1);
  for (int i = 2; i < n; i++) {
    if (cont == n - 1) break;
    cont++;
    custo += i;
  }
  cout << custo << "\n";
}
