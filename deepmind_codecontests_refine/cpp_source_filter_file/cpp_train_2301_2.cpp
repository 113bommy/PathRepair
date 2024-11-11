#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  cout.tie(0);
  int n, k, valore, a[101], massimo, p = 0, somma = 0;
  cin >> n >> k;
  for (int i = 0; i < 101; i++) a[i] = 0;
  for (int i = 0; i < n; i++) {
    cin >> valore;
    a[valore]++;
  }
  massimo = *max_element(a, a + n);
  if (massimo % k != 0) p = k - massimo % k;
  for (int i = 0; i < 101; i++)
    if (a[i] != 0) somma += massimo + p - a[i];
  cout << somma;
  return 0;
}
