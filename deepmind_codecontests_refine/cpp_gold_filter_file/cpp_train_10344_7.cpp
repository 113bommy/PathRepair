#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n;
  int arr[n];
  map<int, int> mp1, mp2;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    mp1[arr[i]] = i + 1;
    mp2[arr[i]] = n - i;
  }
  cin >> m;
  long long sum1 = 0, sum2 = 0;
  int x;
  for (int i = 0; i < m; i++) {
    cin >> x;
    sum1 += mp1[x];
    sum2 += mp2[x];
  }
  cout << sum1 << " " << sum2;
  return 0;
}
