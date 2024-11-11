#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(true);
  int n;
  cin >> n;
  int x;
  cin >> x;
  if (n == 5)
    cout << ">>.>v" << endl
         << "v<.<<" << endl
         << ">>.>v" << endl
         << "v<.<<" << endl
         << ">>>.>" << endl
         << "1 1" << endl;
  else if (n == 3)
    cout << ">.v" << endl << "v.<" << endl << ">.." << endl << "1 1" << endl;
  else {
    for (int rr = 0; rr < 1; rr++) cout << ("v");
    for (int rr = 0; rr < 24; rr++) cout << (".<");
    for (int rr = 0; rr < 25; rr++) cout << ("<<");
    for (int rr = 0; rr < 1; rr++) cout << ("<");
    cout << endl;
    for (int rr = 0; rr < 1; rr++) cout << ("v");
    for (int rr = 0; rr < 49; rr++) cout << (">v");
    for (int rr = 0; rr < 1; rr++) cout << ("^");
    cout << endl;
    for (int i = 0; i < 24; i++) {
      for (int rr = 0; rr < 1; rr++) cout << ("v");
      for (int rr = 0; rr < 49; rr++) cout << ("^v");
      for (int rr = 0; rr < 1; rr++) cout << (".");
      cout << endl;
      for (int rr = 0; rr < 1; rr++) cout << ("v");
      for (int rr = 0; rr < 49; rr++) cout << (".v");
      for (int rr = 0; rr < 1; rr++) cout << ("^");
      cout << endl;
    }
    for (int i = 0; i < 24; i++) {
      for (int rr = 0; rr < 1; rr++) cout << (".");
      for (int rr = 0; rr < 49; rr++) cout << ("^.");
      for (int rr = 0; rr < 1; rr++) cout << ("^");
      cout << endl;
      for (int rr = 0; rr < 1; rr++) cout << ("v");
      for (int rr = 0; rr < 49; rr++) cout << ("^v");
      for (int rr = 0; rr < 1; rr++) cout << ("^");
      cout << endl;
    }
    for (int rr = 0; rr < 50; rr++) cout << (">^");
    cout << endl;
    for (int rr = 0; rr < 100; rr++) cout << (".");
    cout << endl;
    for (int rr = 0; rr < 1; rr++) cout << ("99 0");
    cout << endl;
  }
  return 0;
}
