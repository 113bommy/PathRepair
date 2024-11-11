#include <bits/stdc++.h>
const int Inf = 2 * 1000 * 1000 * 1000;
long long LINF = (long long)4e18;
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(3, 0);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[x]++;
  }
  if (a[2]) {
    cout << 2 << ' ';
    a[2]--;
  }
  if (a[1]) {
    cout << 1 << ' ';
    a[1]--;
  }
  while (a[2]) {
    cout << 2 << ' ';
    a[2]--;
  }
  while (a[1]) {
    cout << 1 << ' ';
    a[1]--;
  }
  return 0;
}
