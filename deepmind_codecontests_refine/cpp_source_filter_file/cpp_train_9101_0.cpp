#include <bits/stdc++.h>
using namespace std;
void FIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void printarr(int arr[], int start, int size) {
  for (int i = start; i < size; i++) {
    cout << arr[i] << " ";
  }
}
long long int arr[1005][1005];
long long int tdp[1005][1005];
long long int rtdp[1005][1005];
long long int botdp[1005][1005];
long long int rbotdp[1005][1005];
int main() {
  int t = 1;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> arr[i + 1][j + 1];
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        tdp[i][j] = arr[i][j] + max(tdp[i - 1][j], tdp[i][j - 1]);
      }
    }
    for (int i = n; i >= 1; i--) {
      for (int j = 1; j <= m; j++) {
        botdp[i][j] = arr[i][j] + max(botdp[i + 1][j], botdp[i][j - 1]);
      }
    }
    for (int i = n; i >= 1; i--) {
      for (int j = m; j >= 1; j--) {
        rtdp[i][j] = arr[i][j] + max(rtdp[i + 1][j], rtdp[i][j + 1]);
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = m; j >= 1; j--) {
        rbotdp[i][j] = arr[i][j] + max(rbotdp[i - 1][j], rbotdp[i][j + 1]);
      }
    }
    long long int ans = 0, tp, api, apj;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        tp = max(
            tdp[i - 1][j] + rtdp[i + 1][j] + botdp[i][j - 1] + rbotdp[i][j + 1],
            tdp[i][j - 1] + rtdp[i][j + 1] + botdp[i + 1][j] +
                rbotdp[i - 1][j]);
        if (tp > ans) {
          ans = tp;
          api = i;
          apj = j;
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
