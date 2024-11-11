#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n & 1) {
    cout << "1 ";
    for (int i = 2; i < n + 1; i++) {
      cout << i + 1 << " " << i << " ";
      i += 2;
    }
    cout << endl;
  } else {
    for (int i = 1; i < n + 1; i++) {
      cout << i + 1 << " " << i << " ";
      i += 2;
    }
    cout << endl;
  }
  return 0;
}
