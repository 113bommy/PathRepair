#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, arr[101], sum = 0, c = 0, d = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < n; i++) {
    if (arr[i] % 2 == 0) {
      c++;
    } else {
      d++;
    }
    sum = sum + arr[i];
  }
  if (sum % 2 == 0) {
    cout << c;
  } else {
    cout << d;
  }
  return 0;
}
