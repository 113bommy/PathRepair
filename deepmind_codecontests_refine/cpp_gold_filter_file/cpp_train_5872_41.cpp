#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 5) {
    cout << ">...v\nv.<..\n..^..\n>....\n..^.<\n1 1";
    return 0;
  }
  if (n == 3) {
    cout << ">vv\n^<.\n^.<\n1 3";
    return 0;
  }
  for (int i = 0; i < 50; i++) {
    for (int j = 0; j < 50; j++) cout << '>';
    for (int j = 0; j < 24; j++) cout << ".>";
    cout << ".v" << endl;
    cout << "^.";
    for (int j = 0; j < 24; j++) cout << "<.";
    for (int j = 0; j < 50; j++) cout << "<";
    cout << endl;
  }
  cout << "1 100";
}
