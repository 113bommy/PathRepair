#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s = 0, A;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> A;
    if (A == 0 && s != 0) {
      cout << "NO";
      return 0;
    }
    s = (s + A) % 2;
  }
  if (s != 0) {
    cout << "NO";
    return 0;
  }
  cout << "YES";
}
