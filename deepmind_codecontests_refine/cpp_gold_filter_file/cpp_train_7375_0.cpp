#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int64_t tuyonowa = 0;
  vector<int> a(3 * n);
  for (int i = 0; i < 3 * n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  for (int i = n; i < 3 * n; i += 2) tuyonowa += a[i];
  cout << tuyonowa;
}