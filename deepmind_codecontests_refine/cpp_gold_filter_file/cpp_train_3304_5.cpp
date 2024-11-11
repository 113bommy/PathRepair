#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  vector<long long> v;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    v.push_back(x);
  }
  long long min = LLONG_MAX, flag = 0, gate;
  for (long long i = 0; i < n; i++) {
    if (min > v[i]) min = v[i];
    if (v[i] <= i) {
      flag = 1;
      gate = i + 1;
      break;
    }
  }
  if (flag == 1) {
    cout << gate;
    return 0;
  }
  if (min > n) {
    min = min / n;
    for (long long i = 0; i < n; i++) v[i] = v[i] - n * min;
  }
  flag = 0;
  long long inc = 0;
  while (1) {
    for (long long i = 0; i < n; i++) {
      if (inc < n)
        min = inc;
      else
        min = n;
      v[i] = v[i] - min;
      if (v[i] <= 0) {
        flag = 1;
        gate = i + 1;
        break;
      }
      inc++;
    }
    if (flag == 1) {
      cout << gate;
      return 0;
    }
  }
  return 0;
}
