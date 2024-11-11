#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  vector<int> a(n);
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum % 3 != 0) {
    cout << 0;
    return 0;
  }
  long long part = sum / 3;
  long long count = 0;
  long long nowsum = 0;
  long long result = 0;
  for (int i = 0; i < n - 1; ++i) {
    nowsum += a[i];
    if (nowsum == part * 2) {
      result += count;
    } else if (nowsum == part) {
      count++;
    }
  }
  cout << result;
}
