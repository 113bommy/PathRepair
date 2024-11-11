#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, t, a[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 2; i <= n; i++) {
    cout << "? 1 " << i << endl;
    cin >> a[i];
  }
  cout << "? 2 3" << endl;
  cin >> a[1];
  a[1] = (a[2] + a[3] - a[1]) / 2;
  cout << "! " << a[1];
  for (int i = 2; i <= n; i++) {
    cout << " " << a[i] - a[1];
  }
  return 0;
}
