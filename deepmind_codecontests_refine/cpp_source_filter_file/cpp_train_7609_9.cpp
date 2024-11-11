#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, cnt = 0;
  cin >> n;
  int arr[1001] = {0};
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  for (int i = 0; i < n; i++) {
    if (arr[i + 1] - arr[i] > 1) cnt = (arr[i + 1] - arr[i]) - 1;
  }
  cout << cnt << endl;
}
