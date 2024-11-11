#include <bits/stdc++.h>
using namespace std;
long long int arr[5001][5001];
int main(int argc, char const *argv[]) {
  long long int a, b, c;
  long long int mod = 998244353;
  cin >> a >> b >> c;
  for (int i = 1; i < 5001; i++) arr[i][1] = arr[1][i] = i + 1;
  for (int i = 2; i < 5001; i++)
    for (int j = 2; j < 5001; j++)
      arr[i][j] = (arr[i - 1][j] + arr[i - 1][j - 1] * j) % mod;
  cout << ((arr[a][b] * arr[a][c]) % mod * arr[b][c]) % mod;
  return EXIT_SUCCESS;
}
