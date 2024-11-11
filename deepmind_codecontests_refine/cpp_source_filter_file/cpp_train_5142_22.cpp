#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const double eps = 1e-9;
const double pi = acos(-1.0);
int main() {
  for (int i = 0; i <= 9; i++) {
    cout << "??" << i << ">>" << i << "??" << endl;
  }
  cout << "??>>?" << endl;
  for (int i = 0; i < 9; i++) {
    cout << i << "?<>" << i + 1 << endl;
  }
  cout << "9?>>0?" << endl;
  cout << "?<>1" << endl;
  cout << ">>??" << endl;
  return 0;
}
