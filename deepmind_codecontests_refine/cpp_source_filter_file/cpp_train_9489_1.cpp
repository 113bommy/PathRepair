#include <bits/stdc++.h>
using namespace std;
int count_nondes(int *n, int start, int end);
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int left = 0, right = n;
  while (left < right) {
    bool flag = true;
    for (int i = left + 1; i < right; i++) {
      if (a[i] < a[i - 1]) {
        flag = false;
      }
    }
    if (flag) {
      cout << right - left << endl;
      return 0;
    } else {
      int mid = left + ((right - left) >> 1);
      if (count_nondes(a, left, mid) > count_nondes(a, mid, right)) {
        right = mid;
      } else {
        left = mid;
      }
    }
  }
  cout << 1 << endl;
}
int count_nondes(int *n, int start, int end) {
  int ret = 0, cur = 1;
  for (int i = start + 1; i < end; i++) {
    if (*(n + i) > *(n + i - 1))
      cur++;
    else {
      cur = 1;
    }
    ret = max(ret, cur);
  }
  return ret;
}
