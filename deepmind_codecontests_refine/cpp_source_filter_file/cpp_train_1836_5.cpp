#include <bits/stdc++.h>
using namespace std;
map<string, int> mapa;
string a, b, c;
int x[100];
bool mayor(int a, int b, int c) {
  if (b < a) {
    if ((b + 12) - a != 4) return false;
  } else {
    if (b - a != 4) return false;
  }
  if (c < b) {
    if ((c + 12) - b != 3) return false;
  } else {
    if (c - b != 3) return false;
  }
  return true;
}
bool menor(int a, int b, int c) {
  if (b < a) {
    if ((b + 12) - a != 3) return false;
  } else {
    if (b - a != 3) return false;
  }
  if (c < b) {
    if ((c + 12) - b != 4) return false;
  } else {
    if (c - b != 4) return false;
  }
  return true;
}
int main() {
  mapa["C"] = 1;
  mapa["C#"] = 2;
  mapa["D"] = 3;
  mapa["D#"] = 4;
  mapa["E"] = 5;
  mapa["F"] = 6;
  mapa["F#"] = 7;
  mapa["G"] = 8;
  mapa["B#"] = 9;
  mapa["A"] = 10;
  mapa["B"] = 11;
  mapa["H"] = 12;
  cin >> a >> b >> c;
  x[0] = mapa[a];
  x[1] = mapa[b];
  x[2] = mapa[c];
  sort(x, x + 3);
  do {
    if (mayor(x[0], x[1], x[2])) {
      cout << "major" << endl;
      return 0;
    } else if (menor(x[0], x[1], x[2])) {
      cout << "minor" << endl;
      return 0;
    }
  } while (next_permutation(x, x + 3));
  cout << "strange" << endl;
  return 0;
}
