#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, count1 = 0, count2 = 0, count3 = 0;
  int arr[100000];
  bool ch = 0;
  cin >> n >> k;
  k--;
  count1 = k - 1;
  count2 = k + 1;
  for (int i = 0; i < n; i++) cin >> arr[i];
  if (arr[k] == 1) count3++;
  for (int i = 0; i < n; i++) {
    if (count1 == -1) {
      ch = 1;
      break;
    }
    if (count2 == n) break;
    if (arr[count1] == 1 && arr[count2] == 1) {
      count3 += 2;
    }
    count1--;
    count2++;
  }
  if (ch == 1) {
    for (int i = count2; i < n; i++)
      if (arr[i] == 1) count3++;
  } else {
    for (int i = count1; i >= 0; i--)
      if (arr[i] == 1) count3++;
  }
  cout << count3;
}
