#include <bits/stdc++.h>
using namespace std;
int tab[100003] = {0};
set<int> liste;
void decomp(int a) {
  if (a == 1 || a == 0) return;
  for (int i = 2; i <= sqrt(a) + 1; i++) {
    if (a % i == 0) {
      liste.insert(i);
      return decomp(a / i);
    }
  }
  liste.insert(a);
  return;
}
int main() {
  ios::sync_with_stdio(false);
  int nb;
  cin >> nb;
  int tot = 1;
  int maxi = 0;
  for (int i = 0; i < nb; i++) {
    int temp;
    cin >> temp;
    decomp(temp);
    for (int j : liste) {
      tab[j]++;
    }
    liste.clear();
    maxi = max(maxi, temp);
  }
  for (int i = 2; i <= maxi; i++) tot = max(tot, tab[i]);
  cout << tot << endl;
}
