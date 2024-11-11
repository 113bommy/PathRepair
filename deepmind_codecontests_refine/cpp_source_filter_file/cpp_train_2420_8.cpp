#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int x;
    cin >> x;
    cout << pow(2, x / 2) - 2 << endl;
  }
}
