#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, n1, n2, i;
  cin >> n >> k;
  long long num = 0;
  for (int c = 0; c < n; c++) {
    cin >> n1 >> n2;
    num += (n2 - n1) + 1;
  }
  if (num <= k)
    cout << num % k << endl;
  else if (num % k == 0)
    cout << 0 << endl;
  else {
    i = ((num / k) + 1) * k;
    cout << i - num << endl;
  }
  return 0;
}
