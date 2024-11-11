#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  int a[1005];
  cin >> n >> k;
  for (int i = 1; i < n + 1; i++) {
    cin >> a[i];
  }
  int minIdx;
  int minCut = 0x6FFFFFFF;
  for (int i = 1; i < n + 1; i++) {
    int count = 0;
    for (int j = 1; j < n + 1; j++) {
      if (a[i] + (j - i) * k < 0) {
        count = 0x6FFFFFFF;
        break;
      }
      if (a[i] + (j - i) * k != a[j]) {
        count++;
      }
    }
    if (count < minCut) {
      minCut = count;
      minIdx = i;
    }
  }
  cout << minCut << endl;
  for (int i = 1; i < n + 1; i++) {
    if (a[minIdx] + (i - minIdx) * k != a[i]) {
      if (a[minIdx] + (i - minIdx) * k > a[i]) {
        cout << "+ " << i << " " << a[minIdx] + (i - minIdx) * k - a[i] << endl;
      } else {
        cout << "- " << i << " " << -(a[minIdx] + (i - minIdx) * k - a[i])
             << endl;
      }
    }
  }
  return 0;
}
