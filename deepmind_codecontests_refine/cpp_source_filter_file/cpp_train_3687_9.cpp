#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int sl = n / k;
  int ans;
  set<int> s;
  int realans = INT_MAX, hma = 0;
  for (int i = 0; i < n / 2; i++) {
    int j = 0, ans = 0;
    while (j < sl) {
      ans += a[(i + k * j) % n];
      s.insert((i + k * j) % n);
      j++;
    }
    if (ans < realans) {
      realans = ans;
      hma = *s.begin();
    }
    s.clear();
  }
  cout << hma + 1;
}
