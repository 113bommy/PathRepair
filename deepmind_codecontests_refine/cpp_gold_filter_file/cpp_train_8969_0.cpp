#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    long long sum = 0, rsum = 0, cnt = 0;
    long long a[n];
    vector<int> p;
    int flag = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (flag) {
        rsum += a[i];
      } else {
        sum += a[i];
        if (sum % 2 != 0) {
          p.push_back(i + 1);
          cnt++;
          sum = 0;
        }
        if (cnt == k) {
          flag++;
        }
      }
    }
    if (!flag) {
      cout << "NO" << endl;
    } else {
      if (rsum % 2 == 0) {
        cout << "YES" << endl;
        for (int i = 0; i < int(p.size() - 1); i++) {
          cout << p[i] << " ";
        }
        cout << n << endl;
      } else
        cout << "NO" << endl;
    }
  }
}
