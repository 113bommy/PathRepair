#include <bits/stdc++.h>
#pragma GCC optimize "-O3"
using namespace std;
void setIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
int main() {
  setIO();
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &i : a) {
    cin >> i;
  }
  long long total = 0;
  for (int i = 0; i < n - 1; i++) {
    int len = 1;
    while (i + len < n) {
      len <<= 1;
    }
    total += a[i];
    cout << total << '\n';
    a[i + (len >> 1)] += a[i];
  }
}
