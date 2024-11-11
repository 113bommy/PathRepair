#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, arr[(int)1e5 + 2], c = 2, mx = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (i > 1 && arr[i] == arr[i - 1] + arr[i - 2])
      c++;
    else
      mx = c, c = 2;
  }
  if (n <= 2) return cout << n, 0;
  return cout << max(mx, c), 0;
}
