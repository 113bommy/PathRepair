#include <bits/stdc++.h>
using namespace std;
struct domino {
  int up, down;
};
int main() {
  int n;
  cin >> n;
  domino arr[n];
  int upsum = 0, downsum = 0;
  bool flag = false;
  for (int i = 0; i < n; i++) {
    cin >> arr[i].up >> arr[i].down;
    upsum += arr[i].up;
    downsum += arr[i].down;
    if ((arr[i].up % 2 == 0 && arr[i].down % 2 != 0) ||
        (arr[i].up % 2 == 0 && arr[i].down % 2 == 0))
      flag = true;
  }
  if ((upsum % 2 == 0 && downsum % 2 != 0) ||
      (upsum % 2 != 0 && downsum % 2 == 0))
    cout << -1;
  else if (upsum % 2 == 0 && downsum % 2 == 0)
    cout << 0;
  else {
    if (flag)
      cout << 1;
    else
      cout << -1;
  }
}
