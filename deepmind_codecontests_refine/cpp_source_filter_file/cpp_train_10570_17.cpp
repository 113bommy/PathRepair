#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long x;
  long long max = -1;
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    cin >> x;
    sum = sum + x;
    if (x > max) max = x;
  }
  cout << sum - max + 1;
}
