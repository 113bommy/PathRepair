#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y;
  cin >> n >> x >> y;
  int array[n];
  for (int i = 0; i < n; i++) {
    cin >> array[i];
  }
  int count = 0;
  if (x > y) {
    cout << n << endl;
  } else {
    for (int i = 0; i < n; i++) {
      if (array[i] <= y) {
        count++;
      }
    }
    cout << count / 2 << endl;
  }
}
