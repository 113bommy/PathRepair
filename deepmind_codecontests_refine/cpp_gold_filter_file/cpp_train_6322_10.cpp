#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int k;
  cin >> k;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int count = 0, index = -1, flag = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] <= k)
      count++;
    else {
      index = i;
      flag = 1;
      break;
    }
  }
  if (flag == 1) {
    for (int i = n - 1; i > index; i--) {
      if (arr[i] <= k)
        count++;
      else
        break;
    }
  }
  cout << count << endl;
  return 0;
}
