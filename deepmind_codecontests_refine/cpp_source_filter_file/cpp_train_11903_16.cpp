#include <bits/stdc++.h>
using namespace std;
int k;
string s;
long long ile[1000005];
int licz() {
  long long wynik = 0;
  int l = s.length();
  int aktual = 0;
  ile[0] = 1;
  for (int i = 0; i < l; i++) {
    if (s[i] == '1') {
      aktual++;
    }
    if (aktual >= k) {
      wynik += ile[aktual - k];
    }
    ile[aktual]++;
  }
  return wynik;
}
int main() {
  cin >> k >> s;
  cout << licz() << "\n";
  return 0;
}
