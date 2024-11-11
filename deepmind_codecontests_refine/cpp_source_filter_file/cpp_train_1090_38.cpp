#include <bits/stdc++.h>
using namespace std;
int main() {
  long long h, n, low, high, mid;
  cin >> h >> n;
  low = 1;
  high = (long long)pow(2, h);
  long long sum = 0, flag = 0;
  while (h) {
    mid = (low + high) / 2;
    if (n > mid && flag == 0) {
      low = mid + 1;
      sum += (long long)pow(2, h);
    } else if (n <= mid && flag == 0) {
      high = mid;
      sum += 1;
      flag = 1;
    } else if (n <= mid && flag == 1) {
      high = mid;
      sum += (long long)pow(2, h);
    } else if (n > mid && flag == 1) {
      low = mid + 1;
      sum += 1;
      flag = 1;
    }
    h--;
  }
  cout << sum << endl;
  return 0;
}
