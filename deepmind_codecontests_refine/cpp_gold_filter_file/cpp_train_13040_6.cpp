#include <bits/stdc++.h>
using namespace std;
long long a[100], b[100];
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    long long aSum = 0;
    long long aMin = 0x7fffffff;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      aSum += a[i];
      aMin = min(aMin, a[i]);
    }
    long long bSum = 0;
    long long bMin = 0x7fffffff;
    for (int i = 1; i <= n; ++i) {
      cin >> b[i];
      bSum += b[i];
      bMin = min(bMin, b[i]);
    }
    long long aMove = aSum - aMin * n;
    long long bMove = bSum - bMin * n;
    for (int i = 1; i <= n; ++i) {
      if (a[i] > aMin && b[i] > bMin) {
        bMove -= min(a[i] - aMin, b[i] - bMin);
      }
    }
    cout << aMove + bMove << endl;
  }
  return 0;
}
