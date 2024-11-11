#include <bits/stdc++.h>
using namespace std;
const int m = 1000000;
int nim[m + 1];
vector<int> v[4];
int calculate(int L, int R) {
  for (int i = 0; i < 4; i++) {
    int lb = lower_bound(v[i].begin(), v[i].end(), L) - v[i].begin();
    int ub = upper_bound(v[i].begin(), v[i].end(), R) - v[i].begin();
    if (lb >= ub) return i;
  }
  return 4;
}
int calculate(long long x) {
  if (x < 4) return 0;
  long long L = int(pow(x, 1.0 / 4.0) - 1);
  while (L * L * L * L < x) L++;
  long long R = int(pow(x, 1.0 / 2.0) + 1);
  while (R * R > x) R--;
  return calculate(L, R);
}
int main() {
  ios::sync_with_stdio(false);
  for (int i = 1; i <= 3; i++) {
    v[0].push_back(i);
    nim[i] = 0;
  }
  int M = 0;
  int L = 1, R = 1;
  for (int i = 4; i <= m; i++) {
    while (L * L * L * L < i) L++;
    while (R * R < i) R++;
    while (R * R > i) R--;
    nim[i] = calculate(L, R);
    v[nim[i]].push_back(i);
    M = max(M, nim[i]);
  }
  int n;
  cin >> n;
  int res = 0;
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    res ^= calculate(x);
  }
  if (res == 0)
    cout << "Rublo" << endl;
  else
    cout << "Furlo" << endl;
  return 0;
}
