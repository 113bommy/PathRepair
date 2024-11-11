#include <bits/stdc++.h>
using namespace std;
int coun[2][9999999];
int arr[300000];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  coun[1][0] = 1;
  int res = 0, x = 0;
  for (int i = 0; i < n; i++) {
    x ^= arr[i];
    res += coun[i % 2][x];
    coun[i % 2][x]++;
  }
  cout << res << endl;
}
