#include <bits/stdc++.h>
using namespace std;
long long int solve(vector<long long int> arr, vector<long long int> sleep,
                    int k) {
  long long int total = 0, curr = 0, sumM = 0;
  for (int i = 0; i < k; i++) {
    curr += (sleep[i] == 0) ? arr[i] : 0;
    total += (sleep[i] == 1) ? arr[i] : 0;
  }
  sumM = max(sumM, curr);
  for (int i = k; i < arr.size(); i++) {
    curr = (sleep[i - k] == 0) ? curr - arr[i] : curr;
    curr = (sleep[i] == 0) ? curr + arr[i] : curr;
    sumM = max(sumM, curr);
    total += (sleep[i] == 1) ? arr[i] : 0;
  }
  return total + sumM;
}
int main() {
  int n, k;
  cin >> n >> k;
  vector<long long int> arr(n), sleep(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < n; i++) cin >> sleep[i];
  cout << solve(arr, sleep, k) << endl;
  return 0;
}
