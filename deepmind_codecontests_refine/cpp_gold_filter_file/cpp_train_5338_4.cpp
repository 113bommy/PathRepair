#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int n;
int main() {
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.begin() + n);
  reverse(a.begin(), a.begin() + n);
  for (int i = 1; i < n - 1; i++) {
    if (i % 2 == 1) swap(a[i], a[i + 1]);
  }
  cout << (int)((n - 1) / 2) << endl;
  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  return 0;
}
