#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (n == 5) {
    cout << ">...v" << endl
         << "v.<.." << endl
         << "..^.." << endl
         << ">...." << endl
         << "..^.<" << endl
         << "1 1";
    return 0;
  }
  if (n == 3) {
    cout << ">vv" << endl << "^<." << endl << "^.<" << endl << "1 3";
    return 0;
  }
  for (int i = 0; i < 50; i++) {
    for (int j = 0; j < 50; j++) {
      cout << '>';
    }
    for (int j = 0; j < 24; j++) {
      cout << ".>";
    }
    cout << ".v" << endl;
    cout << "<.";
    for (int j = 0; j < 24; j++) {
      cout << "<.";
    }
    for (int j = 0; j < 50; j++) {
      cout << '<';
    }
    cout << endl;
  }
  cout << "1 100";
}
