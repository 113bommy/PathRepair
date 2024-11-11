#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, len, arr[100001], table[100001];
  int hi, lo, mid, ans;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> arr[i];
  len = 1;
  table[1] = arr[1];
  for (i = 2; i <= n; i++) {
    if (arr[i] < table[1])
      table[1] = arr[i];
    else if (arr[i] > table[len]) {
      len++;
      table[len] = arr[i];
    } else {
      lo = 1;
      hi = len;
      ans = -1;
      while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (table[mid] < arr[i]) {
          if (ans == -1 || ans < mid) ans = mid;
          lo = mid + 1;
        } else
          hi = mid - 1;
      }
      if (ans != -1) table[ans + 1] = arr[i];
    }
  }
  cout << len << endl;
  return 0;
}
