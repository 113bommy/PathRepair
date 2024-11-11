#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, r;
  long long int min1 = INT_MAX, max1 = INT_MIN;
  cin >> n >> m >> r;
  for (int i = 0; i < n; i++) {
    long long int x;
    cin >> x;
    min1 = min(x, min1);
  }
  for (int i = 0; i < m; i++) {
    long long int x;
    cin >> x;
    max1 = max(x, max1);
  }
  if (min1 >= max1) {
    cout << r;
    return 0;
  }
  long long int sh = r / min1;
  long long int rem = r - sh * min1;
  long long int remm = sh * max1;
  cout << remm + rem;
}
