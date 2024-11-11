#include <bits/stdc++.h>
using namespace std;
int n, last;
int main() {
  cin >> n;
  if (n) {
    n--;
    cout << "0 0\n";
  }
  last = 1;
  while (n >= 3) {
    n -= 3;
    cout << last << " 0\n";
    cout << last + 1 << " 0\n";
    cout << last << " 3\n";
    last += 2;
  }
  if (n) {
    n--;
    cout << last << "0\n";
  }
  if (n) {
    n--;
    cout << last + 1 << "0\n";
  }
  return 0;
}
