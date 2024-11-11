#include <bits/stdc++.h>
using namespace std;
int n, x, mini, minVal = 1 << 30;
int arr[200002];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    arr[x] = i;
  }
  for (int i = 1; i <= 200000; i++) {
    if (arr[i] && arr[i] < minVal) {
      minVal = arr[i];
      mini = i;
    }
  }
  cout << mini << endl;
}
