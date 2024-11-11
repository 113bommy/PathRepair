#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  cin >> n;
  int flag = 0;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (i == 0 && x % 2) flag++;
    if (i == n - 1 && x % 2) flag++;
  }
  if (n % 2) flag++;
  if (flag == 3)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
