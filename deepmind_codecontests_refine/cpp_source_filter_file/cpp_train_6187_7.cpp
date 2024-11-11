#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n;
  cin >> n;
  long long result;
  if (n == 0) {
    result = 0;
  } else if (n == 1) {
    result = 4;
  } else {
    auto k = (long long)(n / sqrt(2));
    result = k * 8;
    if (k * k + (k + 1) * (k + 1) <= n * n) {
      result += 4;
    }
  }
  cout << result << endl;
  return 0;
}
