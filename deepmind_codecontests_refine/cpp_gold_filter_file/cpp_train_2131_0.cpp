#include <bits/stdc++.h>
using namespace std;
int tavan(int a, int b) {
  int result = 1;
  for (int i = 0; i < b; i++) {
    result = a * result;
  }
  return result;
}
int tavan(int a, int b);
int main() {
  long long m;
  long long n;
  cin >> m;
  for (int i = 0; i < 16; i++) {
    m += 1;
    if (m < 0) {
      n = -m;
    } else {
      n = m;
    }
    for (int j = 0; j < 10; j++) {
      int mod = 0;
      mod = n / tavan(10, j) % 10;
      if (mod == 8) {
        cout << i + 1;
        return 0;
      }
    }
  }
}
