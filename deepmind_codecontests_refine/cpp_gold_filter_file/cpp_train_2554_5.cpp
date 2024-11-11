#include <bits/stdc++.h>
using namespace std;
int N, M;
int a[500010];
bool tryGet(long long x) {
  long long res = 0;
  for (int i = 0; i < N; i++) {
    if (a[i] > x) res += a[i] - x;
  }
  return res <= M;
}
bool tryPut(long long x) {
  long long res = 0;
  for (int i = 0; i < N; i++) {
    if (a[i] < x) res += x - a[i];
  }
  return res <= M;
}
int main() {
  while (cin >> N >> M) {
    long long sum = 0;
    for (int i = 0; i < N; i++) {
      cin >> a[i];
      sum += a[i];
    }
    int richest = -1;
    {
      int L = 0, R = 1e9;
      while (L <= R) {
        int mid = (L + R) / 2;
        if (tryGet(mid)) {
          richest = mid;
          R = mid - 1;
        } else {
          L = mid + 1;
        }
      }
    }
    assert(richest != -1);
    int poorest = -1;
    {
      int L = 0, R = 1e9;
      while (L <= R) {
        int mid = (L + R) / 2;
        if (tryPut(mid)) {
          poorest = mid;
          L = mid + 1;
        } else {
          R = mid - 1;
        }
      }
    }
    assert(poorest != -1);
    cout << max(sum % N == 0 ? 0 : 1, richest - poorest) << endl;
  }
  return 0;
}
