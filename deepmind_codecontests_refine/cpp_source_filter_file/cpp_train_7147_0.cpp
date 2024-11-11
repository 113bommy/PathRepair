#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int main() {
  int n, k;
  cin >> n >> k;
  int ar[n][2];
  long long int sum = 0;
  long long int maxi = 0;
  long long int totalsum = 0;
  for (int i = 0; i < n; i++) cin >> ar[i][0];
  for (int i = 0; i < n; i++) {
    cin >> ar[i][1];
    if (ar[i][1] == 1) totalsum += ar[i][0];
  }
  for (int i = 0; i < k; i++)
    if (ar[i][1] == 0) sum += ar[i][0];
  if (sum > maxi) maxi = sum;
  for (int i = k; i < n; i++) {
    if (ar[i][1] == 0) sum += ar[i][0];
    if (ar[i - k][1] == 0) sum -= ar[i][0];
    if (sum > maxi) maxi = sum;
  }
  totalsum += maxi;
  cout << totalsum << endl;
  return 0;
}
