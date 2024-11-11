#include <bits/stdc++.h>
using namespace std;
int main() {
  int w, k, rest;
  cin >> w >> k;
  rest = abs(max(w, k) - 6);
  if (rest + 1 == 3)
    cout << "1/2";
  else if (rest + 1 == 5)
    cout << "5/6";
  else if (rest + 1 == 4)
    cout << "2/3";
  else if (rest + 1 == 3)
    cout << "1/2";
  else if (rest + 1 == 2)
    cout << "1/3";
  else if (rest == 1)
    cout << "1/6";
  else
    cout << "1/1";
  return 0;
}
