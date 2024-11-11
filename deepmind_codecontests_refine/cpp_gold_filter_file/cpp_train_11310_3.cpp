#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int n, m, k;
  cin >> n >> m >> k;
  char a[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> a[i][j];
  }
  vector<long long> v, arr;
  for (int i = 0; i < n; i++) {
    long long c = 0;
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '.')
        c++;
      else if (a[i][j] == '*') {
        if (c >= k) v.push_back(c);
        c = 0;
      }
    }
    if (c >= k) v.push_back(c);
  }
  for (int i = 0; i < m; i++) {
    long long c = 0;
    for (int j = 0; j < n; j++) {
      if (a[j][i] == '.')
        c++;
      else if (a[j][i] == '*') {
        if (c >= k) arr.push_back(c);
        c = 0;
      }
    }
    if (c >= k) arr.push_back(c);
  }
  long long sum = 0, num = 0;
  if (k == 1) {
    for (long long i = 0; i < v.size(); i++) sum += v[i];
    cout << sum << endl;
  } else {
    for (long long i = 0; i < v.size(); i++) sum += v[i] - k + 1;
    for (long long i = 0; i < arr.size(); i++) num += arr[i] - k + 1;
    cout << num + sum << endl;
  }
}
