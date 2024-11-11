#include <bits/stdc++.h>
using namespace std;
long long ans;
int main() {
  vector<int> a(3);
  for (size_t i = 0; i < 3; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  cout << (a[1] + a[0] > a[2]) ? 0 : -a[1] - a[0] + a[2];
}
