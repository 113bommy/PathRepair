#include <bits/stdc++.h>
using namespace std;
long long powmod(long long x, long long y, long long m) {
  long long res = 1LL;
  while (y) {
    if (y & 1) res = (res * x) % m;
    x = (x * x) % m;
    y /= 2;
  }
  return res;
}
long long int n;
vector<pair<long long int, long long int>> a(3003);
bool sortbysec(const pair<long long int, long long int> &a,
               const pair<long long int, long long int> &b) {
  return (a.second < b.second);
}
struct SparseTable {
  using T = long long int;
  long long int n, k;
  vector<vector<pair<T, T>>> table;
  SparseTable(long long int size = 1e6) {
    n = size;
    k = (long long int)(log2(n)) + 1;
    table.assign(k, vector<pair<T, T>>(n));
  }
  inline pair<T, T> func(pair<T, T> a, pair<T, T> b) {
    if (a.first > b.first)
      return a;
    else
      return b;
  }
  void build(vector<T> &arr) {
    for (long long int i = 0; i < n; i++) table[0][i] = {arr[i], i};
    for (long long int j = 1; j <= k; j++) {
      for (long long int i = 0; i + (1 << j) <= n; i++) {
        table[j][i] = func(table[j - 1][i], table[j - 1][i + (1 << (j - 1))]);
      }
    }
  }
  pair<T, T> query(long long int left, long long int right) {
    right = min(right, n);
    long long int length = (right - left + 1);
    long long int K = (long long int)(log2(length));
    return func(table[K][left], table[K][right + 1 - (1 << K)]);
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  SparseTable t(n);
  vector<long long int> b(n);
  for (long long int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  a[n].first = 0;
  a[n].second = n;
  sort(a.begin(), a.begin() + n, greater<pair<long long int, long long int>>());
  for (long long int i = 0; i < n; i++) b[i] = a[i].first - a[i + 1].first;
  t.build(b);
  pair<long long int, pair<long long int, long long int>> ans = {-1, {-1, -1}};
  pair<long long int, pair<long long int, long long int>> ind = {-1, {-1, -1}};
  for (long long int i = 0; i < n; i++) {
    long long int leni = i + 1;
    for (long long int j = i + leni / 2 + leni % 2; 2 * leni >= (j - i); j++) {
      long long int lenj = (j - i);
      long long int mini = j + max(leni, lenj) / 2 + max(leni, lenj) % 2;
      long long int maxi = j + min(leni, lenj) * 2;
      if (mini > n || j > n) continue;
      long long int temp1 = b[i], temp2 = b[j];
      auto temp3 = t.query(mini, maxi);
      pair<long long int, pair<long long int, long long int>> temp = {
          temp1, {temp2, temp3.first}};
      if (ans <= temp) ans = temp, ind = {i, {j, temp3.second}};
    }
  }
  for (long long int i = 0; i < n; i++) {
    if (i <= ind.first)
      a[i].first = 1;
    else if (i <= ind.second.first)
      a[i].first = 2;
    else if (i <= ind.second.second)
      a[i].first = 3;
    else
      a[i].first = -1;
  }
  sort(a.begin(), a.begin() + n, sortbysec);
  for (long long int i = 0; i < n; i++) cout << a[i].first << " ";
  cout << "\n";
}
