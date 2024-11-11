#include <bits/stdc++.h>
using namespace std;
string s, aux;
int i, j, n;
bool check() {
  int i, j;
  for (i = 0, j = n; i <= j; i++, j--)
    if (aux[i] != aux[j]) return 0;
  return 1;
}
int main() {
  cin >> s;
  n = s.size();
  for (i = 0; i <= n; i++) {
    aux = s;
    aux += 'a';
    for (j = n; j >= i; j--) aux[j] = aux[j - 1];
    aux[i] = aux[n - i];
    if (check()) {
      cout << aux;
      return 0;
    }
  }
  cout << "NA";
  return 0;
}
