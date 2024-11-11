#include <bits/stdc++.h>
using namespace std;
long long A[500009], temp[50009];
int main() {
  long long T, N, M, i, j, k = 0, r = 0, c = 0, ans = -1;
  cin >> N;
  for (i = 1; i <= N; i++) {
    cin >> A[i];
    if (i % 7 != 0 && (ans < 0 || A[i] < A[ans])) {
      ans = i;
    }
  }
  if (N % 7 == 0) {
    cout << ans << endl;
    return 0;
  }
  long long low = 1, high = 10000000000000000, mid;
  while (low < high) {
    mid = (low + high) / 2;
    long long cnt = 0;
    for (i = 1; i <= N; i++) {
      temp[i] = A[i];
    }
    for (i = 1; i <= N; i++) {
      temp[i] -= (mid / (N * 7)) * 6;
    }
    long long left = mid % (N * 7);
    for (i = 1; i <= left; i++) {
      if (i % 7 == 0) continue;
      if (i % N == 0)
        temp[N]--;
      else
        temp[i % N]--;
    }
    for (i = 1; i <= N; i++) {
      if (temp[i] <= 0) cnt++;
    }
    if (cnt == 1) {
      for (i = 1; i <= N; i++) {
        if (temp[i] <= 0) {
          cout << i << endl;
          return 0;
        }
      }
    } else if (cnt > 1) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
}
