#include <bits/stdc++.h>
using namespace std;
int main() {
  string code;
  cin >> code;
  map<string, int> decrypt;
  string num;
  for (int i = 0; i < 10; i++) {
    cin >> num;
    decrypt[num] = i;
  }
  for (int i = 0; i < 80; i += 10) {
    cout << decrypt[code.substr(i, 10)] << " ";
  }
  return 0;
}
