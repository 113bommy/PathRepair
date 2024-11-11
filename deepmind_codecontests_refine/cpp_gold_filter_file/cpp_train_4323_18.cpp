#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  cin >> n;
  for (int i = 16; i >= 0; i--) {
    if ((1 << i) <= n) {
      cout << i + 1 << " ";
      n -= (1 << i);
    }
  }
}
