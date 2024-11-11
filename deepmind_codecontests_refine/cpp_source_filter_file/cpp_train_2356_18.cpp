#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, counter = 0;
  int tab[1000];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> tab[i];
  }
  for (int i = 1; i < n; i++) {
    if (tab[i] < tab[i - 1] && tab[i] < tab[i + 1]) counter++;
    if (tab[i] > tab[i - 1] && tab[i] > tab[i + 1]) counter++;
  }
  cout << counter;
}
