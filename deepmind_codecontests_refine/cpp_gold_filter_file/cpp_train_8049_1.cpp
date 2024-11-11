#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int *a = new int[n];
  int max = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    max += a[i];
  }
  for (int del = 2; del < n; del++) {
    int vLeft = n / del;
    if (n % del == 0 && vLeft > 2) {
      for (int j = 0; j < n / vLeft + 1; j++) {
        int done = 0;
        int start = j;
        int sum = 0;
        while (done < vLeft) {
          if (start >= n) start -= n;
          sum += a[start];
          start += del;
          done++;
        }
        if (sum > max) max = sum;
      }
    }
  }
  cout << max;
  return 0;
}
