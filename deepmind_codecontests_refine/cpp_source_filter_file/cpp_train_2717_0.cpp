#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0) return (a);
  a %= b;
  return (gcd(b, a));
}
int main() {
  int n;
  cin >> n;
  vector<long long int> v(n);
  int flag1 = 0;
  int flag2 = 0;
  for (long long int i = 0; i < n; i++) {
    cin >> v[i];
    if (v[i] >= 0) {
      flag1 = 1;
    }
    if (v[i] <= 0) {
      flag2 = 1;
    }
  }
  if (n == 1) {
    cout << v[0];
    return (0);
  }
  sort(v.begin(), v.end());
  long long int sum = 0;
  if (flag1 == 0 && flag2 == 1) {
    for (long long int i = 0; i < n; i++) {
      if (v[i] < 0) {
        sum -= v[i];
      } else {
        sum += v[i];
      }
    }
    cout << sum << endl;
    return (0);
  } else if (flag1 == 1 || flag2 == 1) {
    if (v[1] < 0) {
      for (long long int i = 0; i < n; i++) {
        if (i == n - 1)
          sum += v[i];
        else
          sum -= v[i];
      }
    } else {
      for (long long int i = 0; i < n; i++) {
        if (i == 5) {
          sum -= v[i];
        } else {
          sum += v[i];
        }
      }
    }
    cout << sum << endl;
    return (0);
  }
}
