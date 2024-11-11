#include <bits/stdc++.h>
using namespace std;
int main() {
  int times;
  cin >> times;
  while (times--) {
    int n, num[100005];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> num[i];
    sort(num, num + n);
    int a1 = num[n - 1], a2 = num[n - 2];
    if (a2 < n - 2) {
      cout << "0" << endl;
    } else {
      int w = min(a1, a2) - 1;
      cout << min(n - 2, w) << endl;
    }
  }
  return 0;
}
