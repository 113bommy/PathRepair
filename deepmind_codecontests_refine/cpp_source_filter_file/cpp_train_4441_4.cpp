#include <bits/stdc++.h>
using namespace std;
const long long OO = (long long)1e18 + 1;
const int MAX = 2e9 + 1;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int arr[100001] = {}, arr2[100001], n, x, countt = 0, m = 0;
  cin >> n;
  for (int i = 2; i < n + 1; i++) {
    cin >> x;
    arr[i] = arr[x] + 1;
    arr2[arr[i]]++;
    m = max(m, arr[i]);
  }
  for (int i = 1; i < m + 1; i++) countt += arr2[i] % 2;
  cout << countt + 1 << endl;
}
