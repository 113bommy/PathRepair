#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, sum = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    sum = sum + x;
  }
  if (sum % 2 != 0) {
    cout << n - 1;
  } else {
    cout << n;
  }
}
