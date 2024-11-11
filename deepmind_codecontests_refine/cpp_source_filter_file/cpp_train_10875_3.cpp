#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long n, m, cnt = 0;
  cin >> n >> m;
  long long arr[n][m], a, b, maxi1 = INT_MIN, maxi2 = INT_MIN, ans = 0;
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < m; j++) cin >> arr[i][j];
  cin >> a >> b;
  for (long long i = 0; i < n - a + 1; i++) {
    for (long long j = 0; j < n - b + 1; j++) {
      cnt = 0;
      for (long long p = i; p < i + a; p++) {
        for (long long q = j; q < j + b; q++) {
          if (arr[p][q] == 0) cnt++;
        }
      }
      maxi1 = max(maxi1, cnt);
    }
  }
  for (long long i = 0; i < n - b + 1; i++) {
    for (long long j = 0; j < n - a + 1; j++) {
      cnt = 0;
      for (long long p = i; p < i + b; p++) {
        for (long long q = j; q < j + a; q++) {
          if (arr[p][q] == 0) cnt++;
        }
      }
      maxi2 = max(maxi2, cnt);
    }
  }
  ans = (a * b) - max(maxi1, maxi2);
  cout << (ans) << endl;
}
