#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, n, sum = 0, sum1 = 0, a;
  vector<int> bi;
  cin >> n >> a;
  for (i = 0; i < n; i++) {
    int x;
    cin >> x;
    bi.push_back(x);
    sum = sum + x;
  }
  if (sum == 1) {
    cout << sum << endl;
    return 0;
  }
  int p1, p2;
  p1 = p2 = a - 1;
  for (i = 0; i < n; i++) {
    if ((bi[p1] == 1 && bi[p2] == 1) && p1 == a - 1 && p2 == a - 1) {
      sum1++;
    } else if (bi[p1] == 1 && bi[p2] == 1 && p1 != a - 1 && p2 != a - 1) {
      sum1 += 2;
    }
    p1--;
    p2++;
    if (p1 < 0) {
      for (i = p2; i < n; i++) {
        if (bi[i] == 1) {
          sum1++;
        }
      }
      cout << sum1 << endl;
      return 0;
    } else if (p2 > n) {
      for (i = p1; i >= 0; i--) {
        if (bi[i] == 1) {
          sum1++;
        }
      }
      cout << sum1 << endl;
      return 0;
    }
  }
}
