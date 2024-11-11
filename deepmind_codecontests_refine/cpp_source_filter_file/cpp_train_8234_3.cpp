#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, r;
  cin >> n >> r;
  int arr[n];
  int heaters = 0;
  int freq[n];
  int start = -1, end = -1;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    freq[i] = 0;
    if (arr[i] == 1) heaters++;
  }
  for (int i = 0; i < n; ++i) {
    if (arr[i] == 1) {
      for (int j = i - r + 1; j <= i + r - 1; j++) {
        if (j >= 0 && j < n) {
          freq[j]++;
        }
      }
    }
  }
  bool dead = false;
  for (int i = 0; i < n; ++i) {
    if (freq[i] == 0) {
      dead = true;
      break;
    }
  }
  if (dead) {
    cout << -1 << endl;
    return 0;
  }
  int index = r;
  int count = 0;
  for (int i = 0; i < n; ++i) {
    int j = min(i + r - 1, n - 1);
    while (arr[j] != 1 && j > i) {
      j--;
    }
    count++;
    i = j + r - 1;
  }
  cout << count << endl;
  return 0;
}
