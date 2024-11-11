#include <bits/stdc++.h>
using namespace std;
int main() {
  uint8_t x = 0, y = 0;
  for (int i = 0; i < 8; i++) {
    char s[9];
    cin.getline(s, 9);
    for (int j = 0; j < 8; j++) {
      if (s[j] == 'W') {
        x = x | (1 << j);
        y = y | (1 << i);
      }
    }
  }
  if (x == 255 && y == 255) {
    cout << 8 << endl;
    return 0;
  }
  int count = 0;
  for (int i = 0; i < 8; i++) {
    if (!(x & (1 << i))) count++;
    if (!(y & (1 << i))) count++;
  }
  cout << count << endl;
  return 0;
}
