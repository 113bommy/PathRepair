#include <bits/stdc++.h>
using namespace std;
int n, a[505];
bool judge(int k) {
  int i;
  for (i = 1; i <= n; i++) {
    if (a[i] % k > a[i] / k) return false;
  }
  return true;
}
int cal(int n, int k) {
  int p = n / k - n % k;
  p -= p / (k + 1);
  return p + n % k;
}
int main() {
  cin >> n;
  int i, j;
  for (i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + 1 + n);
  int s = (int)sqrt(a[1]);
  int ans = 1;
  for (i = 1; i <= s; i++) {
    int t = a[1] / i;
    if (judge(t)) {
      ans = t;
      break;
    }
    if (judge(t - 1)) {
      ans = t - 1;
      break;
    }
  }
  if (ans == 1) {
    for (i = s; i >= 0; i--) {
      if (judge(i)) {
        ans = i;
        break;
      }
    }
  }
  int aa = 0;
  for (i = 1; i <= n; i++) {
    aa += cal(a[i], ans);
  }
  cout << aa << endl;
}
