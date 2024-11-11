#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int t = 0;
  if (n > m) {
    t = n;
  } else {
    t = m;
  }
  if (t % 2 == 0) {
    cout << "Malvika" << endl;
  } else {
    cout << "Akshat" << endl;
  }
  return 0;
}
