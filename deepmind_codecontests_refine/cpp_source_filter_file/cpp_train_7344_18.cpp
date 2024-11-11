#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, b, d, arr[100000], counter = 0, sum = 0, container = 0;
  cin >> n >> b >> d;
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < n; i++) {
    if (arr[i] <= b) {
      container += arr[i];
      if (container >= d) {
        counter++;
        container = 0;
      }
    }
  }
  cout << counter;
  return 0;
}
