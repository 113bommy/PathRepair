#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, count = 0;
  cin >> n >> m;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] <= 5) {
      if (5 - arr[i] >= m) {
        count++;
      }
    }
  }
  cout << count / 3 << endl;
}
