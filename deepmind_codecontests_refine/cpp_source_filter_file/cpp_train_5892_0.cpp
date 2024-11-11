#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[100001];
  int n;
  cin >> n;
  int sum = 0;
  int minSub = -100001;
  int minOdd = 100001;
  int t;
  for (int i = 0; i < n; ++i) {
    cin >> t;
    if (t >= 0) {
      sum += t;
      if (t % 2 == 1 && t < minOdd) {
        minOdd = t;
      }
    } else {
      if (t > minSub && abs(minSub) % 2 == 1) minSub = t;
    }
  }
  if (sum % 2 == 1) {
    cout << sum;
  } else {
    if (abs(minOdd) > abs(minSub)) {
      sum += minSub;
    } else {
      sum -= minOdd;
    }
    cout << sum;
  }
  return 0;
}
