#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  cin >> n >> x;
  if (x % 2) {
    int k = 0;
    for (int i = 1; i <= x; i += 2) {
      k++;
    }
    cout << k << endl;
  } else {
    int k = 0;
    for (int i = 0; i <= x; i += 2) {
      k++;
    }
    cout << k << endl;
  }
}
