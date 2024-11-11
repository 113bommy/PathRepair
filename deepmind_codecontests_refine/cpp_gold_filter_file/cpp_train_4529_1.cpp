#include <bits/stdc++.h>
using namespace std;
int dp[5005][5005];
int n, k;
int divi;
int ndiv1, ndiv2;
vector<int> arr;
void init() {
  for (int i = 0; i < 5005; i++)
    for (int j = 0; j < 5005; j++) dp[i][j] = -1;
}
int f(int num1, int num2) {
  int ind = (ndiv1 - num1) * divi + (ndiv2 - num2) * (divi + 1);
  if (dp[num1][num2] != -1) return dp[num1][num2];
  if (num1 == 0 && num2 == 0)
    return 0;
  else if (num1 == 0)
    return dp[num1][num2] = abs(arr[ind] - arr[ind + divi]) + f(num1, num2 - 1);
  else if (num2 == 0)
    return dp[num1][num2] =
               abs(arr[ind] - arr[ind + divi - 1]) + f(num1 - 1, num2);
  int o1 = f(num1 - 1, num2);
  int o2 = f(num1, num2 - 1);
  return dp[num1][num2] = min(abs(arr[ind] - arr[ind + divi - 1]) + o1,
                              abs(arr[ind] - arr[ind + divi]) + o2);
}
int main() {
  init();
  cin >> n >> k;
  int x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    arr.push_back(x);
  }
  ndiv1 = k - (n % k);
  ndiv2 = n % k;
  divi = n / k;
  sort(arr.begin(), arr.end());
  cout << f(ndiv1, ndiv2) << endl;
  return 0;
}
