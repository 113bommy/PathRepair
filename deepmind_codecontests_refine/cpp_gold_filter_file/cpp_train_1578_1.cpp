#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int n1 = 0, n2 = 0;
  int in;
  while (n--) {
    cin >> in;
    if (in == 1)
      n1++;
    else
      n2++;
  }
  if (n2) {
    cout << 2 << ' ';
    n2--;
  }
  if (n1) {
    cout << 1 << ' ';
    n1--;
  }
  while (n2) {
    cout << 2 << ' ';
    n2--;
  }
  while (n1) {
    cout << 1 << ' ';
    n1--;
  }
}
