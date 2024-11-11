#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 2) {
    cout << "white\n1 2\n";
  } else if (n % 2 == 0) {
    cout << "white\n2 1\n";
  } else {
    cout << "black\n";
  }
}
