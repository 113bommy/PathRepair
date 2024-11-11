#include <bits/stdc++.h>
using namespace std;
map<long long, long long> fr1, fr2;
int a[2 * 100000 + 5];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    fr2[a[i]]++;
  }
  long long sol = 0;
  for (int i = 1; i <= n; i++) {
    fr2[a[i]]--;
    if (a[i] % k == 0) sol += fr1[a[i] / k] * fr2[a[i] * k];
    fr1[a[i]]++;
  }
  cout << sol;
  return 0;
}
