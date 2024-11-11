#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M;
  cin >> N >> M;
  int arr[51][51];
  memset(arr, false, sizeof(arr));
  int t;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) {
      cin >> t;
      arr[i][j] = t == 1 ? true : false;
    }
  int ans = 2600;
  int a, b;
  cin >> a >> b;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) {
      int tmp = 0;
      if (i + a <= N && j + b <= M) {
        for (int ii = i; ii < N && ii < i + a; ii++)
          for (int jj = j; jj < M && jj < j + b; jj++)
            if (arr[ii][jj]) tmp++;
        ans = min(ans, tmp);
      }
      tmp = 0;
      swap(a, b);
      if (i + a <= N && j + b <= M) {
        for (int ii = i; ii < N && ii < i + a; ii++)
          for (int jj = j; jj < M && jj < j + b; jj++)
            if (arr[ii][jj]) tmp++;
        ans = min(ans, tmp);
      }
      swap(a, b);
    }
  cout << ans << "\n";
  return 0;
}
