#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  vector<int> a;
  int x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    a.push_back(x);
  }
  int t = 0;
  for (int i = 3; i <= n; i++) {
    if (n % i == 0) {
      for (int j = 0; j <= i; j++) {
        int k = 0;
        for (int l = j; l < n; l += n / i)
          if (a[l] == 1) k++;
        if (k == i)
          t = 1;
        else
          k = 0;
      }
    }
  }
  cout << ((t == 0) ? "NO" : "YES");
  return 0;
}
