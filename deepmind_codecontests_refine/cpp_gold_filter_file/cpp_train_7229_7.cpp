#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int t = 0;
  if (n > m) {
    t = m;
  } else {
    t = n;
  }
  if (t % 2 == 0) {
    cout << "Malvika" << endl;
  } else {
    cout << "Akshat" << endl;
  }
  return 0;
}
