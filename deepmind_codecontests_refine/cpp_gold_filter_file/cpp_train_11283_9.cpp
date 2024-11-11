#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k, n1, n2, sum = 0, count = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> n1 >> n2;
    sum += abs(n1 - n2) + 1;
  }
  for (int i = 0; i < 100000; i++) {
    if (sum % k == 0) {
      break;
    } else {
      sum++;
      count++;
    }
  }
  cout << count;
  return 0;
}
