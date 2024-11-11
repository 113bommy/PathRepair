#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  cin >> n >> m;
  if (n == 5) {
    cout << ">...v" << endl
         << "v.<.." << endl
         << "..^.." << endl
         << ">...." << endl
         << "..^.<" << endl
         << "1 1" << endl;
  } else if (n == 3) {
    cout << ">vv" << endl << "^<." << endl << "^.<" << endl << "1 3" << endl;
  } else {
    cout << ">";
    for (int x = 0; x < 32; x++) {
      cout << ">";
    }
    for (int x = 0; x < 33; x++) {
      cout << ">.";
    }
    cout << "v" << endl;
    for (int z = 0; z < 49; z++) {
      cout << "^v";
      for (int x = 0; x < 33; x++) {
        cout << ".<";
      }
      for (int x = 0; x < 32; x++) {
        cout << "<";
      }
      cout << endl << "^";
      for (int x = 0; x < 32; x++) {
        cout << ">";
      }
      for (int x = 0; x < 33; x++) {
        cout << ">.";
      }
      cout << "v" << endl;
      ;
    }
    cout << "^";
    for (int x = 0; x < 33; x++) {
      cout << ".<";
    }
    for (int x = 0; x < 33; x++) {
      cout << "<";
    }
    cout << "1 1" << endl;
  }
}
