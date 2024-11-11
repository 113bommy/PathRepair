#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int k;
void update(int* arr, int idx) {
  while (idx <= n) {
    arr[idx] += 1;
    idx += idx & (-idx);
  }
}
int ret(int* arr, int idx) {
  int sum = 0;
  while (idx > 0) {
    sum += arr[idx];
    idx -= idx & (-idx);
  }
  return sum;
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m;
    int arr[n + 1];
    int fen[n + 1];
    memset(fen, 0, sizeof fen);
    for (int x = 1; x <= n; x++) {
      cin >> k;
      arr[k] = x;
    }
    int res = 0;
    int pos = 0;
    for (int x = 1; x <= m; x++) {
      cin >> k;
      if (arr[k] < pos) {
        res++;
        update(fen, 1);
      } else {
        res += (2 * (arr[k] - ret(fen, arr[k]) - 1)) + 1;
        update(fen, arr[k]);
      }
      pos = max(pos, arr[k]);
    }
    cout << res << endl;
  }
}
