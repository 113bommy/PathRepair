#include <bits/stdc++.h>
using namespace std;
int main() {
  int b[] = {'a', 3,   'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 0,   'l', 'm',
             3,   'o', 1,   9,   5,   's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  int w[] = {'A', 3,   'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 0,   'L', 'M',
             3,   'O', 1,   9,   5,   'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
  int ww = 0, bb = 0;
  for (int i = 0; i < 64; i++) {
    char c;
    cin >> c;
    if (c - '.')
      if (c < 'a')
        ww += w[c - 'A'];
      else
        bb += b[c - 'a'];
  }
  if (bb == ww) cout << "Draw";
  if (bb < ww) cout << "White";
  if (bb > ww) cout << "Black";
}
