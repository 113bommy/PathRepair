#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int ar[n];
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  sort(ar, ar + n);
  long long t(1), sum(0);
  for (int i = 0; i < (n / 2); i++) {
    sum += ((ar[i] + ar[n - t]) * (ar[i] + ar[n - t]));
    t++;
  }
  cout << sum << '\n';
  return 0;
}
