#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int arr[1001];
int main() {
  int n, m, c;
  cin >> n >> m >> c;
  fill(arr, arr + n + 1, -1);
  int mid = (c + 1) / 2;
  bool done = 0;
  for (int j = 0; !done && j < m; j++) {
    int x;
    cin >> x;
    if (x > mid) {
      for (int i = n; i >= 1; i--) {
        if (arr[i] == -1 || arr[i] < x) {
          arr[i] = x;
          cout << i << endl;
          break;
        }
      }
    } else {
      for (int i = 1; i <= n; i++) {
        if (arr[i] == -1 || arr[i] > x) {
          arr[i] = x;
          cout << i << endl;
          break;
        }
      }
    }
    done = 1;
    for (int i = 1; done && i <= n; i++) {
      if (arr[i] == -1) {
        done = 0;
        break;
      }
      if (i < n && arr[i + 1] == -1) {
        done = 0;
        break;
      }
      if (i < n && arr[i] > arr[i + 1]) {
        done = 0;
        break;
      }
    }
  }
  exit(0);
}
