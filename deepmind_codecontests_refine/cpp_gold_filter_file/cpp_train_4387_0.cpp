#include <bits/stdc++.h>
using namespace std;
int main() {
  string table;
  string hand;
  cin >> table;
  int sum = 0;
  for (int i = 0; i < 5; i++) {
    cin >> hand;
    if (hand[0] == table[0] or hand[1] == table[1]) {
      sum = sum + 1;
    }
  }
  if (sum > 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
