#include <bits/stdc++.h>
using namespace std;
int k;
int main() {
  cin >> k;
  for (int i = 0; i < 26; i++) {
    for (int f = 2000; f >= 2; f--) {
      if ((f * f - f) / 2 <= k) {
        k -= f * f / 2;
        k += f / 2;
        for (int j = 0; j < f; j++) cout << (char)(i + 'a');
        break;
      }
    }
  }
  cout << 'z';
}
