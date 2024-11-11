#include<iostream>
#include<string>
using namespace std;

int main() {
  int c[9];
  for (int i = 0; i < 9; i++) cin >> c[i];
  int dif = c[3] - c[0]; string res = "Yes";
  for (int i = 1; i < 3; i++) {
    if (c[i + 3] - c[i] != dif) res = "No";
  }
  dif = c[6] - c[0];
  for (int i = 1; i < 3; i++) {
    if (c[i + 6] - c[i] != dif) res = "No";
  }
  cout << res << endl;
}