#include <bits/stdc++.h>
const int mod = 1e9 + 7;
const int maxn = 2e5 + 10;
using namespace std;
int num[maxn];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> num[i];
    }
    if (n == 1) {
      cout << num[1] << endl;
      continue;
    } else if (n == 2) {
      if ((1LL * num[1] * num[2]) < 0) {
        cout << 1LL * num[1] + num[2] << endl;
      } else {
        cout << max(num[1], num[2]) << endl;
      }
      continue;
    }
    int i = 1;
    long long result = 0;
    while (i <= n) {
      int temp = num[i];
      while ((i + 1) <= n && (1LL * num[i] * num[i + 1]) > 0) {
        temp = max(temp, num[i]);
        i++;
      }
      temp = max(temp, num[i]);
      result += temp;
      i++;
    }
    cout << result << endl;
  }
  return 0;
}
