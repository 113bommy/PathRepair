#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long n, k;
  cin >> n >> k;
  long long input[n];
  for (int i = 0; i < n; i++) cin >> input[i];
  map<long long, long long> m;
  long long left[n], right[n];
  for (int i = 0; i < n; i++) {
    if (input[i] % k == 0)
      left[i] = m[input[i] / k];
    else
      left[i] = 0;
    m[input[i]]++;
  }
  m.clear();
  for (int i = n - 1; i >= 0; i--) {
    right[i] = m[input[i] * k];
    m[input[i]]++;
  }
  long long res = 0;
  for (int i = 0; i < n; i++) res += left[i] * right[i];
  cout << res << endl;
  return 0;
}
