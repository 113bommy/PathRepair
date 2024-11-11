#include <bits/stdc++.h>
long long int mod = 1000000000 + 7;
long long int inf = 1000000000000000000;
using namespace std;
int main() {
  iostream::sync_with_stdio(false);
  cin.tie(0);
  vector<int> a(6);
  for (int i = 0; i < 6; i++) cin >> a[i];
  cout << (a[0] + a[1] + a[2]) * (a[0] + a[1] + a[2]) - a[0] * a[0] -
              a[1] * a[1] - a[2] * a[2];
}
