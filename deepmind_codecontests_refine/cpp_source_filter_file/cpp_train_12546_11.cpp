#include <bits/stdc++.h>
using namespace std;
long long n, result, y;
int main() {
  y = 0x3f3f3f3f;
  cin >> n;
  long long numbers[n];
  result = 0;
  for (long long i = 0; i < n; i++) {
    cin >> numbers[i];
    result += numbers[i];
    if (result % 2) {
      y = min(y, numbers[i]);
    }
  }
  if (result % 2) {
    result -= y;
  }
  cout << result;
}
