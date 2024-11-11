#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k, sum = 0;
  cin >> n >> k;
  int arr[200];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  int mx = 0;
  for (int i = 0; i < k; i++) {
    int tempsum = sum;
    for (int j = i; j < n; j += k) {
      if (arr[j] > 0) {
        tempsum--;
      } else {
        tempsum++;
      }
    }
    mx = max(mx, abs(tempsum));
  }
  cout << mx << endl;
  return 0;
}
