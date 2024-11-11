#include <bits/stdc++.h>
using namespace std;
int arr[3][3];
int idx(char c) {
  if (c == 'R') return 0;
  if (c == 'G') return 1;
  if (c == 'B') return 2;
}
int get(int end, int k) {
  int res = INT_MAX, start = (end - k + 1) % 3, temp = 0;
  for (int i = 0; i < 3; i++) {
    temp = 0;
    for (int j = 0; j < 3; j++) {
      int x = (start + j) % 3;
      int y = (i + j) % 3;
      int target = k / 3 + ((k % 3) > j ? 1 : 0);
      temp += (target - arr[x][y]);
    }
    res = min(res, temp);
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int q, n, k, j;
  char c;
  cin >> q;
  while (q--) {
    cin >> n >> k;
    string s;
    cin >> s;
    memset(arr, 0, sizeof(int) * 9);
    for (int i = 0; i < k; i++) {
      j = idx(s[i]);
      arr[i % 3][j]++;
    }
    int res = get(k - 1, k);
    for (int i = k; i < n; i++) {
      j = idx(s[i]);
      arr[i % 3][j]++;
      arr[(i - k)][idx(s[i - k])]--;
      res = min(res, get(i, k));
    }
    cout << res << endl;
  }
  return 0;
}
