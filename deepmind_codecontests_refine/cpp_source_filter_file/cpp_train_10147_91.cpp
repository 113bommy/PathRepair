#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n % 2)
    cout << "black" << endl;
  else {
    cout << "white" << endl;
    cout << n / 2 << ' ' << n << endl;
  }
}
