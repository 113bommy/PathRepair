#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ar[n + 5];
  int i;
  for (i = 0; i < n; i++) cin >> ar[i];
  sort(ar, ar + n);
  ar[n] = -1;
  int cnt = 1, arr[n + 5], cnt2 = 0, arrr[n + 5], cnt3 = 0, cnt6 = 0;
  for (i = 0; i < n; i++) {
    if (ar[i] == ar[i + 1])
      cnt++;
    else {
      arr[cnt2++] = cnt;
      arrr[cnt3++] = ar[i];
      cnt = 1;
      cnt6++;
    }
  }
  int cnt4 = 0, cnt5 = 0;
  for (i = 0; i < cnt2; i++) {
    if (arr[i] == 2)
      cnt4++;
    else if (arr[i] >= 3) {
      cout << "NO" << endl;
      return 0;
    } else if (arr[i] == 1)
      cnt5++;
  }
  cout << "YES" << endl;
  cout << cnt4 << endl;
  for (i = 0; i < cnt2; i++) {
    if (arr[i] == 2) cout << arrr[i] << " ";
  }
  cout << endl;
  cout << cnt6 << endl;
  ar[-1] = -1;
  for (i = n - 1; i >= 0; i--) {
    if ((ar[i] != ar[i - 1])) cout << ar[i] << " ";
  }
  cout << endl;
  return 0;
}
