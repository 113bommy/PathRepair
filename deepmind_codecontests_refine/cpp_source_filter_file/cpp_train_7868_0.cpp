#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int n;
  cin >> n;
  long long a[n], sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum % 2 == 1 || n == 1) {
    cout << "NO";
  } else {
    sum /= 2;
    long long temp1 = 0, temp2;
    map<long long, bool> m1, m2;
    bool flag = false;
    for (int i = 0, j = n - 1; i < n, j >= 0; i++, j--) {
      temp1 += a[i];
      temp2 += a[j];
      m1[a[i]] = 1;
      m2[a[j]] = 1;
      if (temp1 == sum || temp2 == sum) {
        flag = true;
        break;
      }
      if (temp1 > sum) {
        if (m1[temp1 - sum] == 1) {
          flag = true;
          break;
        }
      }
      if (temp2 > sum) {
        if (m2[temp2 - sum] == 1) {
          flag = true;
          break;
        }
      }
    }
    if (flag == true) {
      cout << "YES";
    } else {
      cout << "NO";
    }
  }
  return 0;
}
