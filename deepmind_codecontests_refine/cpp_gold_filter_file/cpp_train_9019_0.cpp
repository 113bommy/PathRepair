#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7, N = 1e6 + 1;
int main() {
  long long n;
  cin >> n;
  long long arr[6] = {0};
  for (long long i = 0; i < n; i++) {
    long long a, b;
    cin >> a >> b;
    arr[a]++;
    arr[b]++;
  }
  for (long long i = 1; i < 6; i++) {
    if (arr[i] >= 3 || arr[i] <= 1) {
      cout << "WIN";
      return 0;
    }
  }
  cout << "FAIL";
  return 0;
}
