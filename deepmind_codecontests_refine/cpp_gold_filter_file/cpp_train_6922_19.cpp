#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, x, y;
  cin >> n >> m >> x >> y;
  int arr1[n], arr2[m];
  for (int i = 1; i <= n; i++) cin >> arr1[i];
  int flag = 1;
  for (int i = 1; i <= m; i++) cin >> arr2[i];
  if (arr1[x] < arr2[m - y + 1])
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
