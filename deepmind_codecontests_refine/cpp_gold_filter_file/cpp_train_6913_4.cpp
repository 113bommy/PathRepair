#include <bits/stdc++.h>
using namespace std;
int sn(int k) {
  int ret = k, ret1 = 0;
  while (ret > 9) {
    while (ret > 0) {
      ret1 += ret % 10;
      ret /= 10;
    }
    ret = ret1;
    ret1 = 0;
  }
  return ret;
}
int main() {
  int k, d, p = -1;
  cin >> k >> d;
  int arr[1001] = {0}, poss[1001];
  for (int i = 0; i <= 1000; i++) {
    poss[i] = sn(i);
  }
  for (int i = 0; i < 1001; i++) {
    if (poss[i] == d) {
      p = i;
      break;
    }
  }
  for (int i = 0; i < k; i++) arr[i] = 1;
  int t = k;
  while (t != p) {
    if (t < p) {
      for (int i = 0; i < k; i++) {
        if (t + 8 <= p) {
          t += 8;
          arr[i] += 8;
        } else {
          arr[i] += (p - t);
          break;
        }
      }
      if (t == p) break;
    } else {
      for (int i = k - 1; i >= 0; i--) {
        if (t - 1 >= p) {
          t--;
          arr[i]--;
        } else
          break;
      }
      if (t == p) break;
    }
  }
  if (k != 1 && d == 0)
    cout << "No solution\n";
  else {
    for (int i = 0; i < k; i++) cout << arr[i];
  }
  return 0;
}
