#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      sum += x;
    }
    int min = sum / n;
    int max = ceil((double)sum / n);
    cout << max - min;
    cout << endl;
  }
  return 0;
}
