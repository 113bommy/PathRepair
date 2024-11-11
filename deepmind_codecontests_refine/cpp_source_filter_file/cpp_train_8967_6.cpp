#include <bits/stdc++.h>
using namespace std;
void testCase() {}
long long M = 1e6 + 3;
long long binpow(long long a, long long b, long long m) {
  long long ans = 1;
  while (b > 0) {
    if (b & 1) ans = ans * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return ans;
}
void gaussjordan(vector<vector<long long>> &v) {
  int n = v.size();
  int m = v[0].size();
  for (int i = 0; i < m - 1; i++) {
    for (int j = i; j < n; j++) {
      if (v[j][i] != 0) {
        swap(v[i], v[j]);
        break;
      }
    }
    if (v[i][i] == 0) continue;
    long long inv = binpow(v[i][i], M - 2, M);
    for (int j = i; j < m; j++) {
      v[i][j] *= inv;
      v[i][j] %= M;
    }
    for (int j = i + 1; j < n; j++) {
      if (v[j][i] != 0) {
        long long x = v[j][i];
        for (int k = i; k < m; k++) {
          v[j][k] -= x * v[i][k];
          v[j][k] %= M;
          if (v[j][k] < 0) v[j][k] += M;
        }
      }
    }
  }
  if (v[m - 2][m - 2] == 0) {
    cout << "Multiple solutions" << endl;
    return;
  }
  for (int i = m - 2; i >= 0; i--) {
    for (int j = i - 1; j >= 0; j--) {
      long long x = v[j][i];
      v[j][i] = 0;
      v[j][m - 1] -= x * v[i][m - 1];
      v[j][m - 1] %= M;
      if (v[j][m - 1] < 0) v[j][m - 1] += M;
    }
  }
}
long long get_val(vector<long long> &polynom, long long x) {
  int n = polynom.size();
  long long ans = 0;
  long long kerroin = 1;
  for (int i = 0; i < n; i++) {
    ans += kerroin * polynom[i];
    ans %= M;
    kerroin *= x;
    kerroin %= M;
  }
  return ans;
}
int main() {
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  vector<vector<long long>> v;
  vector<long long> polynom;
  for (int i = 0; i < 50; i++) {
    vector<long long> w;
    long long x = abs((int)rng()) % 1000000;
    cout << "? " << x << endl;
    long long value;
    cin >> value;
    long long kerroin = 1;
    for (int j = 0; j < 10; j++) {
      w.push_back(kerroin);
      kerroin *= x;
      kerroin %= M;
    }
    w.push_back(value);
    v.push_back(w);
  }
  gaussjordan(v);
  for (int i = 0; i < 10; i++) {
    polynom.push_back(v[i][10]);
  }
  int ans = -1;
  for (int i = 0; i < M; i++) {
    int x = get_val(polynom, i);
    if (x == 0) {
      ans = i;
      break;
    }
  }
  cout << "! " << ans << endl;
}
