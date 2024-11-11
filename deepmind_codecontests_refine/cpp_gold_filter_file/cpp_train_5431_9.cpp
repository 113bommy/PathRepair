#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;
int dp[101][3];
int main() {
  int n, i;
  cin >> n;
  float a[n];
  long long sum = 0;
  vector<int> v;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  int p = 0;
  for (i = 0; i < n; i++) {
    int k = (int)a[i];
    if (a[i] == k) {
      v.push_back(k);
    } else {
      if (p % 2 == 0) {
        int x = ceil(a[i]);
        if (x == 0)
          v.push_back(0);
        else
          v.push_back(x);
        p = p + 1;
      } else {
        int x = floor(a[i]);
        if (x == 0)
          v.push_back(0);
        else
          v.push_back(x);
        p = p + 1;
      }
    }
  }
  for (i = 0; i < n; i++) sum = sum + v[i];
  p = 0;
  i = 0;
  if (sum != 0) {
    if (sum > 0) {
      while (i < n && sum != 0) {
        if (v[i] != a[i]) {
          if (p % 2 == 0) {
            v[i] = v[i] - 1;
            sum--;
          }
          p = p + 1;
        }
        i++;
      }
    } else if (sum < 0) {
      while (i < n && sum != 0) {
        if (v[i] != a[i]) {
          if (p % 2 != 0) {
            v[i] = v[i] + 1;
            sum++;
          }
          p = p + 1;
        }
        i++;
      }
    }
  }
  for (i = 0; i < n; i++) cout << v[i] << "\n";
}
