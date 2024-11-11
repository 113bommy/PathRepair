#include <bits/stdc++.h>
using namespace std;
void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}
int main() {
  int tt;
  cin >> tt;
  int n, diff, sft, row, col, k;
  while (tt--) {
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    int count = 0;
    for (int i = 1;; i++) {
      int chck = 0;
      for (int j = 2; j <= n; j++) {
        if (arr[j - 1] < arr[j])
          chck++;
        else
          break;
      }
      if (chck == n - 1) break;
      if (i % 2 == 0) {
        for (int j = 1; j <= n; j++) {
          if (j % 2 == 0)
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
        }
      } else {
        for (int j = 1; j <= n; j++)
          if (j % 2)
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
      }
      count++;
    }
    cout << count << endl;
  }
  return 0;
}
