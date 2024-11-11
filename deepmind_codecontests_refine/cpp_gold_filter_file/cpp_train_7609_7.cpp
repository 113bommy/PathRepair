#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  long long stolen = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] - a[i - 1] > 1) stolen += a[i] - a[i - 1] - 1;
  }
  cout << stolen << "\n";
}
