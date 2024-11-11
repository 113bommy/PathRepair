#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int k = n % 10, m = n / 10;
  if (k == 1 || k == 7 || k == 9) {
    cout << "NO";
    exit(0);
  }
  if (m == 12) {
    cout << "YES";
    exit(0);
  }
  if (m == 2 || m == 7 || m == 9 || m == 1) {
    cout << "NO";
    exit(0);
  }
  cout << "YES";
}
