#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n;
  long long int m;
  cin >> m >> n;
  vector<long long int> per(n, 1);
  for (long long int i = 0; i < n; i++) {
    cout << m << endl;
    cin >> per[i];
    if (per[i] == 0) {
      return 0;
    }
  }
  long long int l = 0;
  long long int r = m;
  long long int i = 0;
  long long int x;
  while (l + 2 < r) {
    long long int mid = (l + r) / 2;
    cout << mid << endl;
    cin >> x;
    if (x * per[i] == -1) {
      l = mid;
    } else if (x * per[i] == 1) {
      r = mid;
    } else {
      return 0;
    }
    i = (i + 1) % n;
  }
  cout << l + 1 << endl;
  cin >> x;
  if (x == 0) {
    return 0;
  }
  cout << l + 2 << endl;
  cin >> x;
  return 0;
}
