#include <bits/stdc++.h>
using namespace std;
int n, k, x;
int t[100];
int sum = 0;
int main() {
  cin >> n >> k >> x;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  sort(t, t + n);
  for (int j = n - k - 1; j < n; j++) {
    t[j] = x;
  }
  for (int i = 0; i < n; i++) {
    sum += t[i];
  }
  cout << sum << endl;
  ;
}
