#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, temp = 0;
  cin >> n;
  string str;
  cin >> str;
  int t = n, i, count, arr[n], k = 0;
  count = 0;
  for (i = 0; i < n - 1; i++) {
    if (str[i] == 'B' && str[i + 1] == 'B') {
      count++;
    } else if (str[i] == 'B' && str[i + 1] == 'W') {
      count++;
      arr[k] = count;
      k++;
      count = 0;
    } else if (str[i] == 'W') {
      t--;
    }
  }
  if (str[n - 1] == 'B') {
    count++;
    arr[k] = count;
    k++;
  }
  if (k == 0)
    cout << 0 << endl;
  else {
    cout << k << endl;
    for (int j = 0; j < k; j++) cout << arr[j] << " ";
    cout << endl;
  }
  return 0;
}
