#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  cin >> x;
  for (int i = x - 1; i >= 1; i--) {
    for (int j = i - 1; j >= 1; j--) {
      if (i % j == 0 && i * j > x && i / j < x) {
        cout << i << ' ' << j;
        return 0;
      }
    }
  }
  cout << "-1";
}
