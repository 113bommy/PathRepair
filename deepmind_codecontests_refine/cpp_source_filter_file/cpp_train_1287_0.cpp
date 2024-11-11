#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n;
  int x;
  long long sum = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    sum += x;
  }
  if (sum % x) {
    cout << n - 1;
  } else
    cout << n;
  return 0;
}
