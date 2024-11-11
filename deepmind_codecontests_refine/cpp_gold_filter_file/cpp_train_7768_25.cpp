#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, sum = 0, tip;
  cin >> n >> x;
  sum = n;
  for (int i = 0; i < n; i++) {
    cin >> tip;
    sum += tip;
  }
  if (sum - 1 == x)
    cout << "YES";
  else
    cout << "NO";
  cout << endl;
  return 0;
}
