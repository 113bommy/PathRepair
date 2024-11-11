#include <bits/stdc++.h>
using namespace std;
int n, tab[1000001];
void draw() {
  for (int i = 0; i < n; i++) {
    cout << tab[i] << " ";
  }
  cout << endl;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> tab[i];
  }
  sort(tab, tab + n);
  if (n % 2 == 1) {
    cout << tab[n / 2] << endl;
  } else {
    cout << tab[n / 2 - 1] << endl;
  }
  return 0;
}
