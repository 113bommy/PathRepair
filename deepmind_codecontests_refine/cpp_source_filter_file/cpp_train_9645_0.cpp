#include <bits/stdc++.h>
using namespace std;
const long long OO = (long long)1e18 + 1;
const int MAX = 2e9 + 1;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, x, arr[601] = {}, z = 0, countt = 0, maxx = 0;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x, arr[x] = 1, maxx = max(maxx, arr[i]);
  if (maxx) countt++;
  for (int i = 1; i < 600; i++)
    if (i != maxx && arr[i]) countt++;
  cout << countt << endl;
}
