#include <bits/stdc++.h>
using namespace std;
void solveMain() {
  int n;
  cin >> n;
  string str;
  cin >> str;
  int zero = -1;
  for (int i = 0; i < n; i++) {
    if (str[i] == '0') {
      zero = i;
      break;
    }
  }
  if (zero == -1) {
    cout << "1 " << n - 1 << " 2 " << n << '\n';
    return;
  }
  if (zero < n / 2) {
    cout << zero + 1 << " " << n << " " << zero + 2 << " " << n << '\n';
  } else {
    cout << "1 " << zero + 1 << " 1 " << zero << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solveMain();
  }
  return 0;
}
