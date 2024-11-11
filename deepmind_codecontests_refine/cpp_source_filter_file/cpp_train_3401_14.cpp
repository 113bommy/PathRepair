#include <bits/stdc++.h>
using namespace std;
long long poww(long long a, long long b) {
  long long res = 1;
  a %= 1000000007;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % 1000000007;
    a = a * a % 1000000007;
  }
  return res;
}
int main() {
  long long n, arr[200005], i, diff, temp1 = -1, temp2 = -1, hash[200005];
  map<long long, long long> m;
  map<long long, long long>::iterator it;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
    m[arr[i]] = 1;
  }
  sort(arr, arr + n);
  for (i = 0; i < n; i++) {
    for (long long j = 1; j < 32; j++) {
      diff = (1 << j);
      it = m.find(arr[i] + diff);
      if (it != m.end()) {
        temp1 = arr[i];
        temp2 = arr[i] + diff;
        it = m.find(arr[i] + 2 * diff);
        if (it != m.end()) {
          cout << 3 << '\n'
               << arr[i] << " " << arr[i] + diff << " " << arr[i] + 2 * diff;
          return 0;
        }
      }
    }
  }
  if (temp1 != -1 && temp2 != -1) {
    cout << 2 << '\n' << temp1 << " " << temp2;
    return 0;
  }
  cout << 1 << '\n' << arr[0];
  return 0;
}
