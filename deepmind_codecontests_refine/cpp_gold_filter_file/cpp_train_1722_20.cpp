#include <bits/stdc++.h>
using namespace std;
int n;
int k;
int a[1000009];
int b[1000009];
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int j = 0; j < n; j++) cin >> b[j];
  long long l = 0, r = 200000, mid;
  while (l < r) {
    mid = (long long)(l + r + 1) / 2;
    int ans1 = k;
    for (int i = 0; i < n; i++) {
      ans1 = ans1 - max((long long)0, a[i] * mid - b[i]);
    }
    if (ans1 >= 0)
      l = mid;
    else
      r = mid - 1;
  }
  cout << r;
}
