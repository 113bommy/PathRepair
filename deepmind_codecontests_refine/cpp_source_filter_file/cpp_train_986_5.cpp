#include <bits/stdc++.h>
using namespace std;
const int MAXK = 1000;
const int mod = 1000000007;
int arr[MAXK + 10];
int acc[MAXK + 10];
int ncr[MAXK + 10][MAXK + 10];
int main() {
  int k;
  cin >> k;
  for (int i = 1; i <= k; i++) cin >> arr[i];
  for (int i = 1; i <= k; i++) acc[i] = acc[i - 1] + arr[i];
  for (int i = 0; i <= MAXK; i++) ncr[i][0] = 1;
  for (int i = 1; i <= MAXK; i++)
    for (int j = 1; j <= MAXK; j++)
      ncr[i][j] = (ncr[i - 1][j] + ncr[i - 1][j - 1]) % mod;
  long long res = 1;
  for (int i = 2; i <= k; i++)
    res = (res * ncr[acc[i - 1] + 1][arr[i] - 1]) % mod;
  cout << res << endl;
}
