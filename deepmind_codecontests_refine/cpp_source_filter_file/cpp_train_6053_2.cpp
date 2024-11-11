#include <bits/stdc++.h>
using namespace std;
long long int i, j, n, m, k, l, q, t, a, b, sum, tot, cnt;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int arr[4];
  for (i = 0; i <= 3; i++) cin >> arr[i];
  if (arr[0] != arr[3]) {
    cout << 0;
    return 0;
  }
  if (arr[0] == 0 && arr[1] == 0 && arr[3] != 0) {
    cout << 0;
    return 0;
  }
  cout << 1;
  return 0;
}
