#include <bits/stdc++.h>
using namespace std;
int M, N;
string s;
const int MAX = 2005;
const int MOD = 1000000007;
int main() {
  int n, m;
  while (cin >> n >> m) {
    int arr[1005];
    for (int i = 0; i < m; i++) cin >> arr[i];
    sort(arr, arr + m);
    bool b = 1;
    int sum = 0;
    for (int i = 0; i < m; i++) {
      if (sum <= n)
        sum += arr[i];
      else {
        b = 0;
        break;
      }
    }
    puts((b) ? "YES" : "NO");
  }
  return 0;
}
