#include <bits/stdc++.h>
using namespace std;
long long BS(long long array[], long long num, long long f, long long l) {
  long long t = 0;
  while (l >= f) {
    long long m = f + (l - f) / 2;
    if (array[m] <= num) {
      f = m + 1;
      t = m;
    } else
      l = m - 1;
  }
  return t + 1;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  long long n, q;
  cin >> n >> q;
  long long arr[n];
  for (int i = 0; i < n && cin >> arr[i]; i++)
    ;
  sort(arr, arr + n);
  while (q--) {
    long long num;
    cin >> num;
    cout << BS(arr, num, 0, n - 1) << " ";
  }
}
