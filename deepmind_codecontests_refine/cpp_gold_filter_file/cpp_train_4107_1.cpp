#include <bits/stdc++.h>
using namespace std;
long long int arr[100100];
vector<long long int> v[100100];
inline long long int ABS(long long int k) {
  if (k >= 0) return k;
  return -k;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) cin >> arr[i];
  if (m <= 2) {
    printf("0\n");
    return 0;
  }
  long long int sum = 0;
  for (int i = 0; i < m - 1; i++) sum += ABS(arr[i] - arr[i + 1]);
  long long int ma = 0;
  for (int i = 1; i < m - 1; i++) {
    if (arr[i] != arr[i - 1]) v[arr[i]].push_back(arr[i - 1]);
    if (arr[i] != arr[i + 1]) v[arr[i]].push_back(arr[i + 1]);
  }
  if (arr[0] != arr[1]) v[arr[0]].push_back(arr[1]);
  if (arr[m - 1] != arr[m - 2]) v[arr[m - 1]].push_back(arr[m - 2]);
  for (int i = 1; i <= n; i++)
    if (v[i].size()) {
      long long int t = 0;
      sort(v[i].begin(), v[i].end());
      for (int j = 0; j < v[i].size(); j++) t += ABS(i - v[i][j]);
      for (int j = 0; j < v[i].size(); j++)
        t -= ABS(v[i][v[i].size() / 2] - v[i][j]);
      ma = max(ma, t);
    }
  cout << sum - ma << endl;
  return 0;
}
