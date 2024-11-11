#include <bits/stdc++.h>
using namespace std;
long long n, k, cnt, sum;
int main() {
  long long tmp;
  cin >> n >> k >> tmp;
  for (int i = 2; i <= n; i++) {
    long long ai;
    cin >> ai;
    long long di = sum - (i - 1 - cnt) * (n - i) * ai;
    if (di < k) {
      cout << i << endl;
      cnt++;
    } else {
      sum += ai * (i - 1 - k);
    }
  }
  return 0;
}
