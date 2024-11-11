#include <bits/stdc++.h>
using namespace std;
int main() {
  char c;
  int e;
  cin >> c >> e;
  if ((c == 'a' || c == 'h') && (e == 1 || e == 8))
    cout << "3" << endl;
  else if ((c >= 'b' && c == 'g') && (e == 2 || e == 7))
    cout << "5" << endl;
  else if ((c == 'a' || c == 'h') && (e == 2 && e == 7))
    cout << "5" << endl;
  else
    cout << "8" << endl;
}
