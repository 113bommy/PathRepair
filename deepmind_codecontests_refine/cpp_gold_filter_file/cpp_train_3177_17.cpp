#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[3];
  int b[3];
  bool can_transfer[3];
  int transfer[3];
  int total_transfer = 0;
  int total_can_transfer = 0;
  for (int i = 0; i < 3; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < 3; i++) {
    cin >> b[i];
    if (b[i] > a[i]) {
      total_transfer += b[i] - a[i];
      can_transfer[i] = false;
    } else {
      can_transfer[i] = true;
    }
  }
  for (int i = 0; i < 3; i++) {
    if (can_transfer[i])
      if (b[i] != 0)
        total_can_transfer += floor((a[i] - b[i]) / 2);
      else
        total_can_transfer += (a[i] - b[i]) / 2;
  }
  if (total_can_transfer >= total_transfer)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
