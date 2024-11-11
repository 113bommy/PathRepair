#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  long long arr[n];
  cin >> arr[0];
  long long sum = 0L;
  long long count = 1L;
  for (long long i = 1; i < n; i++) {
    cin >> arr[i];
    long long po = (n - i - 1L);
    long long temp = count * (po * arr[i]);
    if (sum - temp < k)
      cout << i + 1 << endl;
    else {
      sum = sum + (count - 1L) * arr[i];
      count++;
    }
  }
  return 0;
}
