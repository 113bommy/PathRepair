#include <bits/stdc++.h>
using namespace std;
int f1[1005], f2[1005];
int main() {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  for (int i = 0; i < n; i++) {
    f1[a[i] - '0']++;
    f2[b[i] - '0']++;
  }
  int ans1 = 0;
  int rem = 0;
  for (int i = 9; i >= 0; i--) {
    if (f1[i] <= f2[i] + rem) {
      rem += f2[i] - f1[i];
    } else {
      ans1 = f1[i] - f2[i] - rem;
      rem = 0;
    }
  }
  int ans2 = 0;
  for (int i = 0; i < 9; i++) {
    for (int j = i + 1; j <= 9; j++) {
      if (f2[j] >= f1[i]) {
        ans2 += f1[i];
        f2[j] -= f1[i];
        f1[i] = 0;
      } else {
        ans2 += f2[j];
        f1[i] -= f2[j];
        f2[j] = 0;
      }
    }
  }
  cout << ans1 << "\n" << ans2;
  return 0;
}
