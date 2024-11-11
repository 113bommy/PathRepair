#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[100005];
  for (int i = 0; i < 100005; i++) {
    arr[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    arr[t]++;
  }
  int res = 1;
  for (int i = 2; i <= 100000; i++) {
    int j = i * 2, cnt = arr[i];
    while (j <= 100000) {
      if (arr[j]) {
        cnt += arr[j];
      }
      j += i;
    }
    res = max(res, cnt);
  }
  cout << res << endl;
  return 0;
}
