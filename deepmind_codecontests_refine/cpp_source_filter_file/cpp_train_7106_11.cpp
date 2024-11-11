#include <bits/stdc++.h>
using namespace std;
map<long long int, long long int> a;
long long int arr[500], brr[500];
vector<long long int> v[500], v2[500];
long long int f(long long int x, long long int i) {
  long long int temp = 1;
  while (i) {
    temp = temp * 2;
    i--;
  }
  return x + temp;
}
long long int check(long long int x, long long int i) {
  while (x) {
    long long int temp = 1, j = 0;
    while (temp <= x) {
      temp = temp * 2;
      j++;
    }
    temp = temp / 2;
    j--;
    x = x - temp;
    if (j == i) return 1;
  }
  return 0;
}
int main() {
  long long int n, m, ans = 0, flag;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < m; i++) cin >> brr[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) v[i].push_back(j);
  }
  for (int k = 10; k >= 0; k--) {
    for (int i = 0; i < n; i++) v2[i].clear();
    flag = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < v[i].size(); j++) {
        long long int val = (arr[i] & brr[v[i][j]]);
        if (check(val, k) == 0) v2[i].push_back(j);
      }
    }
    for (int i = 0; i < n; i++) {
      if (v2[i].size() == 0) {
        flag = 0;
      }
    }
    if (flag) {
      for (int i = 0; i < n; i++) v[i].clear();
      for (int i = 0; i < n; i++)
        for (int j = 0; j < v2[i].size(); j++) v[i].push_back(v2[i][j]);
    } else {
      ans = f(ans, k);
    }
  }
  cout << ans << "\n";
  return 0;
}
