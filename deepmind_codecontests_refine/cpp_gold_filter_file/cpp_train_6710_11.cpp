#include <bits/stdc++.h>
using namespace std;
char bits[1000];
int main() {
  int bit_number, count = 0;
  cin >> bit_number;
  for (int i = 0; i < bit_number; i++) {
    cin >> bits[i];
  }
  int i = 0;
  while (bits[i] == '1') {
    count++;
    i++;
  }
  cout << min(bit_number, ++count);
  return 0;
}
