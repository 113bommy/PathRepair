#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int mx = 1;
  for (int i = 0; i < n; ++i) {
    if (a[i] > mx) {
      ++mx;
    }
  }
  cout << mx + 1 << endl;
}
