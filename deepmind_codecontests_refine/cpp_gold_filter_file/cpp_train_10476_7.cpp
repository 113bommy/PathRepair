#include <bits/stdc++.h>
using namespace std;
int main() {
  string old_napis;
  cin >> old_napis;
  string napis = "";
  for (int i = 0; i < old_napis.length(); i++) {
    char tmp = old_napis[i];
    if (tmp == 'Q' || tmp == 'A') {
      napis = napis + tmp;
    }
  }
  int tab[1000];
  tab[0] = 0;
  int ptr = 0;
  for (int i = 0; i < napis.length(); i++) {
    if (napis[i] == 'Q') ptr++;
    tab[i] = ptr;
  }
  int wynik = 0;
  if (napis.length() < 3) {
    cout << "0";
  } else {
    for (int i = 0; i < napis.length(); ++i) {
      if (napis[i] == 'A') {
        wynik += tab[i] * (ptr - tab[i]);
      }
    }
    cout << wynik;
  }
  return 0;
}
