#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int reqcards = n - 10;
  if (reqcards <= 0) {
    cout << 0 << endl;
  } else if (reqcards == 1) {
    cout << 5 << endl;
  } else if (2 <= reqcards && reqcards <= 9) {
    cout << 4 << endl;
  } else if (reqcards == 10) {
    cout << 15 << endl;
  } else if (reqcards == 11) {
    cout << 1 << endl;
  } else {
    cout << 0 << endl;
  }
}
