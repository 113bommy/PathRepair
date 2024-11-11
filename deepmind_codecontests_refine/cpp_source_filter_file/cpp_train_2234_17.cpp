#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  cin >> n >> m;
  int now = n / 2;
  int kam = now;
  int wa = 0;
  if (n < m) {
    cout << -1 << endl;
    return 0;
  }
  if (now % 2 != 0) {
    now++;
  }
  while (now % m != 0) {
    kam--;
    if (kam < 0) {
      wa = 1;
    }
    now++;
  }
  if (wa) {
    cout << -1 << endl;
  } else {
    cout << now << endl;
  }
  return 0;
}
