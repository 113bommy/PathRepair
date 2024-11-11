#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, input, k, j, c = 0;
  cin >> n;
  vector<long long int> v[n];
  for (i = 0; i < n; i++) {
    cin >> k;
    for (j = 0; j < k; j++) {
      cin >> input;
      v[i].push_back(input);
    }
    sort(v[i].begin(), v[i].end());
  }
  for (i = 0; i < n; i++) {
    long long int r = 0, m = 0;
    long long int prev = i - 1;
    long long int next = i + 1;
    if (i == 0) prev = n - 1;
    if (i == n - 1) next = 0;
    for (j = 0; j < v[i].size() - 1; j++) {
      long long int l1 = 0;
      long long int l2 = 0;
      while (r < v[prev].size() && v[prev][r] <= v[i][j + 1]) {
        if (v[prev][r] >= v[i][j]) l1++;
        r++;
      }
      while (m < v[next].size() && v[next][m] <= v[i][j + 1]) {
        if (v[prev][m] >= v[i][j]) l2++;
        m++;
      }
      if (l2 != l1) c++;
    }
  }
  cout << c << endl;
}
