#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  vector<long long> v(7);
  long long sum = 0;
  long long p = 0;
  for (long long i = 0; i < 7; i++) {
    cin >> v[i];
    sum += v[i];
    if (v[i] != 0) {
      p = i;
    }
  }
  long long sum1 = n % sum;
  if (sum == 0) {
    cout << p + 1;
    return 0;
  }
  for (long long i = 0; i < 7; i++) {
    sum1 -= v[i];
    if (sum1 <= 0) {
      p = i;
      break;
    }
  }
  cout << p + 1;
  return 0;
}
