#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
int main() {
  unsigned int t;
  cin >> t;
  while (t--) {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
      sum += arr[i];
      if (arr[i] == 0) {
        count++;
      }
    }
    if (count > 0) {
      while (sum + count <= 0) {
        count++;
      }
      cout << count << endl;
    } else if (count == 0) {
      if (sum == 0) {
        cout << 1 << endl;
      } else {
        cout << 0 << endl;
      }
    }
  }
}
