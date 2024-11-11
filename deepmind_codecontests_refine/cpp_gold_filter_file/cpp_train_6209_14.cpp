#include <bits/stdc++.h>
using namespace std;
int main() {
  string first, second;
  cin >> first >> second;
  cout << first[0];
  for (int i = 1; i < first.size(); i++) {
    if (first[i] < second[0])
      cout << first[i];
    else
      break;
  }
  cout << second[0];
  return 0;
}
