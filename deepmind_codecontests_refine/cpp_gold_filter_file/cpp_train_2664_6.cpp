#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  n -= 3;
  cout << "ROY";
  int reminder = n % 4;
  n /= 4;
  while (n) {
    cout << "GBIV";
    n--;
  }
  if (reminder == 1)
    cout << "G" << endl;
  else if (reminder == 2)
    cout << "GB" << endl;
  else if (reminder == 3)
    cout << "GBI" << endl;
}
int main() { solve(); }
