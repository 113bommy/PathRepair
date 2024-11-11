#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, ans = 0;
  cin >> n;
  long long int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  int i = 0, j = 1;
  while (j != n) {
    if (arr[i] < arr[j])
      i++, j++, ans++;
    else
      j++;
  }
  cout << ans << endl;
  return 0;
}
