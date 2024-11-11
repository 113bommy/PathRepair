#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a[100];
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x % m == 0)
      a[i] = (x / m);
    else
      a[i] = ceil(x / m);
  }
  int ans = 0, pos = 0;
  for (int i = 0; i < n; i++)
    if (a[i] >= ans) {
      ans = a[i];
      pos = i + 1;
    }
  cout << pos << endl;
}
