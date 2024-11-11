#include <bits/stdc++.h>
using namespace std;
int main() {
  char dir;
  cin >> dir;
  int d;
  if (dir == 'R')
    d = -1;
  else
    d == 1;
  char keyboard[30] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
                       'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',
                       'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/'};
  string mole;
  cin >> mole;
  for (int i = 0; i < mole.size(); i++) {
    for (int j = 0; j < 30; j++) {
      if (mole[i] == keyboard[j]) cout << keyboard[j + d];
    }
  }
  return 0;
}
