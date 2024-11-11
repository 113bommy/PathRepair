#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  if (n % 2 == 0 && k > n / 2)
    k = n / 2;
  else if (n % 2 == 1 && k > (n / 2 + 1))
    k = n / 2 + 1;
  long long sum = 0;
  long long x = n - 1;
  for (int i = 0; i < k; i++) {
    sum += x;
    x--;
  }
  if (n - 2 * k < 0)
    sum += 0, k--;
  else
    sum += (n - 2 * k) * k;
  x = k - 1;
  for (int i = 0; i < k; i++) {
    sum += x;
    x--;
  }
  if (sum < 0)
    cout << 0;
  else
    cout << sum;
  return 0;
}
