#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::string;
int main() {
  string original;
  cin >> original;
  for (int i = 0; i < original.length(); i++) {
    cout << original[i];
  }
  for (int j = original.length(); j >= 0; j--) {
    cout << original[j];
  }
}
