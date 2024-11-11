#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  cin >> n >> x;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    int ai;
    cin >> ai;
    sum += ai;
  }
  sum += n - 1;
  if (sum == x)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
