#include <bits/stdc++.h>
using namespace std;
void solve_A();
void solve_B();
void solve_C();
void solve_D();
void solve_E();
void solve_F();
void solve_G();
void solve_H();
void solve_I();
void solve_J();
int main() {
  int nTests = 1;
  cin >> nTests;
  while (nTests--) solve_A();
  return EXIT_SUCCESS;
}
void solve_A() {
  int n, c0, c1, h;
  cin >> n >> c0 >> c1 >> h;
  string s;
  cin >> s;
  int count = 0;
  bool changeZerosToOnes = c0 > c1 && c0 - c1 > h;
  bool changeOnesToZeros = c1 > c0 && c1 - c0 > h;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0') {
      if (changeZerosToOnes) {
        count += h;
        count += c1;
      } else {
        count += c0;
      }
    } else {
      if (changeOnesToZeros) {
        count += h;
        count += c0;
      } else {
        count += c1;
      }
    }
  }
  cout << count << endl;
}
void solve_B() {}
void solve_C() {}
void solve_D() {}
void solve_E() {}
void solve_F() {}
void solve_G() {}
void solve_H() {}
void solve_I() {}
void solve_J() {}
