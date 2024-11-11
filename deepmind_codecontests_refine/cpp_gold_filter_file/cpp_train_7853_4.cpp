#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long arr[n];
  long long mi = INT_MAX, ma = INT_MIN;
  unordered_map<long long, long long> m;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    m[arr[i]]++;
    mi = min(mi, arr[i]);
    ma = max(ma, arr[i]);
  }
  long long sum = ma - mi;
  cout << sum << " ";
  if (sum == 0) {
    long long a = (n * (n - 1)) / 2;
    cout << a;
  } else
    cout << (long long)m[mi] * m[ma];
}
