#include <bits/stdc++.h>
using namespace std;
int main() {
  bool on[100];
  int button, bulb;
  cin >> button >> bulb;
  int b;
  int temp;
  for (int i = 0; i < 100; i++) {
    on[i] = false;
  }
  for (int i = 0; i < button; i++) {
    cin >> b;
    for (int i = 0; i < b; i++) {
      cin >> temp;
      on[temp - 1] = true;
    }
  }
  int count = 0;
  for (int i = 0; i < 100; i++) {
    if (on[i] == 1) {
      count++;
    }
  }
  if (count == bulb) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return (0);
}
