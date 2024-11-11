#include <bits/stdc++.h>
using namespace std;
long long int t, n, k, m;
long long int A[100001];
long long int M = 1e9 + 7;
bool isSubsetSum(int set[], int n, int sum) {
  if (sum == 0) return true;
  if (n == 0) return false;
  if (set[n - 1] > sum) return isSubsetSum(set, n - 1, sum);
  return isSubsetSum(set, n - 1, sum) ||
         isSubsetSum(set, n - 1, sum - set[n - 1]);
}
int main() {
  long long int k;
  cin >> n >> k;
  if (2 * n <= k * (k - 1))
    cout << "no solution" << endl;
  else {
    for (int i = 0; i < n; i++) cout << "0 " << i << endl;
  }
  return 0;
}
