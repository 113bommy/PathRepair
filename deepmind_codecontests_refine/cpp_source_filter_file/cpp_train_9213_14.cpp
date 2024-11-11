#include <bits/stdc++.h>
using namespace std;
int a[100001];
int pr[5] = {0, 1, 0, 1, 2};
int get(int x) {
  if (x < 5) {
    return pr[x];
  }
  if (x % 2 == 0) return 0;
  return 2 - ((get(x / 2) + 1) & 1);
}
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  if (k % 2 == 0) {
    for (int i = 0; i < n; i++) {
      if (a[i] >= 3) {
        a[i] = (a[i] - 1) % 2;
      }
      ans ^= a[i];
    }
  } else {
    for (int i = 0; i < n; i++) {
      a[i] = get(a[i]);
      ans ^= a[i];
    }
  }
  if (ans > 0) {
    cout << "Kevin";
  } else {
    cout << "Nicky";
  }
  return 0;
}
