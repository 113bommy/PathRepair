#include <bits/stdc++.h>
using namespace std;
int pos[100001];
int arr[100001];
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  long long res = 0;
  for (int i = 0; i < n; cin >> pos[i++])
    ;
  for (int i = 0; i < n; cin >> arr[i++])
    ;
  for (int i = 0; i < n; i++) {
    if (pos[i] * 2 >= arr[i] && arr[i] / 2 != 0) {
      res += (long long)((arr[i] / 2) * (arr[i] - (arr[i] / 2)));
    } else
      res--;
  }
  cout << res;
  return 0;
}
