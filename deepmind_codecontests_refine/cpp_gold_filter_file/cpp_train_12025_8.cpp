#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n], pri[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i] >> pri[i];
  }
  int i = 0, cnt = 0;
  while (i < n) {
    int temp = arr[i], tempi = i;
    while (pri[tempi] < pri[i + 1] && i + 1 < n) {
      if (i + 1 < n)
        i++;
      else
        break;
      temp += arr[i];
    }
    cnt += temp * pri[tempi];
    i++;
  }
  cout << cnt << endl;
}
