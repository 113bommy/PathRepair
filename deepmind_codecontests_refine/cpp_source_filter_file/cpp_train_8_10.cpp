#include <bits/stdc++.h>
using namespace std;
int main() {
  int eig = 0, oth = 0, num = 0;
  int n;
  cin >> n;
  char tab[n];
  string cards;
  cin >> cards;
  for (int i = 0; i < n; i++) tab[i] = cards.at(i);
  for (int i = 0; i < n; i++) {
    if (tab[i] == '8') eig++;
  }
  oth = n;
  while ((oth > 9) && (eig > 0)) {
    num++;
    eig--;
    oth -= 11;
  }
  cout << num;
}
