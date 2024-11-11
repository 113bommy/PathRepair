#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i])
      arr[i] = -1;
    else
      arr[i] = 1;
  }
  int max = 0;
  int curr = 0;
  int s = 0;
  int l = 0;
  int r = 0;
  for (int i = 0; i < n; i++) {
    curr += arr[i];
    if (curr < 0) {
      s = i + 1;
      curr = 0;
    }
    if (max < curr) {
      l = s;
      r = i;
      max = curr;
    }
  }
  int c = 0;
  for (int i = 0; i < n; i++) {
    if (i < l || i > r) {
      if (arr[i] == -1) c++;
    } else {
      if (arr[i] == 1) c++;
    }
  }
  cout << c;
}
