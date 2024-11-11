#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, hasil, N = 0, I = 0, T = 0, E = 0;
  string s;
  cin >> s;
  for (i = 0; i < s.length(); i++) {
    if (s[i] == 'n') {
      N++;
    } else if (s[i] == 'i') {
      I++;
    } else if (s[i] == 't') {
      T++;
    } else if (s[i] == 'e') {
      E++;
    }
  }
  hasil = (N - 1) / 2;
  if (hasil > I) hasil = I;
  if (hasil > T) hasil = T;
  if (hasil > E / 3) hasil = E;
  printf("%d", hasil);
}
