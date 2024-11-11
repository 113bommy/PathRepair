#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  long long int a[n];
  long long int t1 = 0, t2 = 0;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (long long int i = 1; i < n; i = i + 2) {
    t2 += a[i];
  }
  for (long long int i = 2; i < n; i = i + 2) {
    t1 += a[i];
  }
  long long int count = 0;
  if (t1 == t2) {
    count++;
  }
  for (long long int i = 0; i < n; i++) {
    if ((i + 1) % 2 == 0) {
      t2 -= a[i];
      t2 += a[i - 1];
    } else {
      t1 -= a[i];
      t1 += a[i - 1];
    }
    if (t1 == t2) {
      count++;
    }
  }
  cout << count << endl;
}
int main() {
  solve();
  return 0;
}
