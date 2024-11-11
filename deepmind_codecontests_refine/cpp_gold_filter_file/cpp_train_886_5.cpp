#include <bits/stdc++.h>
using namespace std;
const int M = 1000000007;
const int N = 5001;
long long arr[N], ans[N];
int main() {
  long long n, i, j;
  cin >> n;
  vector<long long> v(n);
  for (i = 0; i < n; i++) {
    cin >> v[i];
    ans[i + 1] = 0;
  }
  long long h = 0;
  for (i = 0; i < n; i++) {
    for (j = 1; j <= n; j++) arr[j] = 0;
    h = i;
    for (j = i; j < n; j++) {
      arr[v[j]]++;
      if (arr[v[j]] > arr[h] || (arr[v[j]] == arr[h] && (v[j] < h))) h = v[j];
      ans[h]++;
    }
  }
  for (i = 1; i <= n; i++) cout << ans[i] << ' ';
  cout << endl;
}
