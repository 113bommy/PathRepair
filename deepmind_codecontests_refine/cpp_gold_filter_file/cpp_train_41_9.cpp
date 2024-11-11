#include <bits/stdc++.h>
using namespace std;
long long int base(long long int n, long long int k) {
  string res = "";
  long long int temp = 0, i;
  while (n >= k) {
    res += to_string(n % k);
    n /= k;
  }
  res += to_string(n);
  reverse(res.begin(), res.end());
  for (i = 0; i < res.length(); i++) {
    temp = temp * 10 + (res[i] - '0');
  }
  return temp;
}
int main() {
  long long int n, i, j, flag = 0;
  cin >> n;
  flag = 9;
  for (i = 1; i <= n - 1; i++) {
    for (j = 1; j <= n - 1; j++) {
      cout << base(i * j, n) << " ";
    }
    cout << endl;
  }
  return 0;
}
