#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  char arr[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cin >> arr[i][j];
  }
  long long result = 0;
  long long fact[101];
  fact[0] = 0;
  for (int i = 1; i < 100; i++) fact[i] = (i * (i - 1)) / 2;
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) cnt += arr[i][j] == 'C' ? 1 : 0;
    result += fact[cnt];
  }
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) cnt += arr[j][i] == 'C' ? 1 : 0;
    result += fact[cnt];
  }
  cout << result;
}
