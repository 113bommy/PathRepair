#include <bits/stdc++.h>
using namespace std;
long long n, s, a[200000];
long long can(long long k) {
  vector<long long> a1(n);
  for (int i = 0; i < n; i++) a1[i] = a[i] + k * (i + 1);
  sort(a1.begin(), a1.end());
  long long sum = 0;
  for (int i = 0; i < k; i++) {
    sum += a1[i];
    if (sum > s) return -1;
  }
  return sum;
}
int main() {
  cin >> n >> s;
  for (int i = 0; i < n; i++) cin >> a[i];
  long long l = 0, r = n, mid;
  while (l != r) {
    mid = (l + r) / 2;
    can(mid) != -1 ? (l = mid + 1) : r = mid;
  }
  if (can(r) == -1) r--;
  cout << r << " " << can(r) << endl;
  return 0;
}
