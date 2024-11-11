#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int s, v = 0;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] > arr[i + 1]) {
      s = i + 1;
      v++;
    }
  }
  if (arr[n - 1] > arr[0]) {
    s = n;
    v++;
  }
  if (v == 0)
    cout << "0" << endl;
  else {
    if (v > 1)
      cout << "-1" << endl;
    else
      cout << n - s << endl;
  }
  return 0;
}
