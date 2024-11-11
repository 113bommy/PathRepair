#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a1;
  cin >> a1;
  for (int f = 0; f < a1; f++) {
    int n;
    cin >> n;
    long long int odd[n / 2 + 3], even[n / 2 + 3], o = 0, e = 0;
    long long int ans = 0;
    for (int i = 0, val; i < n; i++) {
      cin >> val;
      if (i % 2) {
        odd[o++] = val;
      } else {
        even[e++] = val;
        ans += val;
      }
    }
    long long int maone = 0, matwo = 0, val = 0;
    for (int i = 0; i < n / 2; i++) {
      val = max(odd[i] - even[i], val + odd[i] - even[i]);
      maone = max(maone, val);
    }
    val = 0;
    for (int i = 1; i < n / 2; i++) {
      val = max(odd[i - 1] - even[i], val + odd[i - 1] - even[i]);
      matwo = max(matwo, val);
    }
    if (n % 2) {
      matwo = max(
          matwo, max(odd[o - 1] - even[e - 1], val + odd[o - 1] - even[e - 1]));
    }
    cout << ans + max(maone, matwo) << "\n";
  }
  return 0;
}
