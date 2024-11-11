#include <bits/stdc++.h>
using namespace std;
template <class T>
long long size(const T& x) {
  return x.size();
}
#pragma GCC optimize("Ofast")
template <class T>
T smod(T a, T b) {
  return (a % b + b) % b;
}
long long _mergeSort(long long arr[], long long temp[], long long left,
                     long long right);
long long merge(long long arr[], long long temp[], long long left,
                long long mid, long long right);
long long temp[300000];
long long mergeSort(long long arr[], long long array_size) {
  return _mergeSort(arr, temp, 0, array_size - 1);
}
long long _mergeSort(long long arr[], long long temp[], long long left,
                     long long right) {
  long long mid, inv_count = 0;
  if (right > left) {
    mid = (right + left) / 2;
    inv_count += _mergeSort(arr, temp, left, mid);
    inv_count += _mergeSort(arr, temp, mid + 1, right);
    inv_count += merge(arr, temp, left, mid + 1, right);
  }
  return inv_count;
}
long long merge(long long arr[], long long temp[], long long left,
                long long mid, long long right) {
  long long i, j, k;
  long long inv_count = 0;
  i = left;
  j = mid;
  k = left;
  while ((i <= mid - 1) && (j <= right)) {
    if (arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
      inv_count = inv_count + (mid - i);
    }
  }
  while (i <= mid - 1) temp[k++] = arr[i++];
  while (j <= right) temp[k++] = arr[j++];
  for (i = left; i <= right; i++) arr[i] = temp[i];
  return inv_count;
}
long long count_inversions(vector<bool> C) {
  long long cnt = 0;
  long long ans = 0;
  for (long long i = (0); i < (C.size()); ++i) {
    if (C[i] == 1)
      cnt++;
    else
      ans += cnt;
  }
  return ans;
}
vector<long long> X(40);
long long ans = 0;
void dc(long long n, vector<long long> A, long long at) {
  if (at == -1 || n == 0) return;
  vector<bool> B;
  vector<long long> BR;
  vector<long long> CR;
  for (long long i = (0); i < (n); ++i) {
    bool fnd = A[i] & (1 << at);
    if (fnd) {
      BR.push_back(A[i]);
    } else {
      CR.push_back(A[i]);
    }
    B.push_back(fnd);
  }
  long long ans1 = count_inversions(B);
  vector<bool> C = B;
  for (long long i = (0); i < (n); ++i) C[i] = !C[i];
  long long ans2 = count_inversions(C);
  ans += min(ans1, ans2);
  X[at] += ans1 - ans2;
  dc(BR.size(), BR, at - 1);
  dc(CR.size(), CR, at - 1);
}
long long b[300000];
void solve() {
  long long n;
  cin >> n;
  vector<long long> A(n);
  for (long long i = (0); i < (n); ++i) cin >> A[i];
  dc(n, A, 39);
  long long x = 0;
  for (long long i = (0); i < (40); ++i) {
    if (X[i] > 0) x |= (1 << i);
  }
  for (long long i = (0); i < (n); ++i) b[i] = A[i] ^ x;
  cout << mergeSort(b, n) << ' ' << x << endl;
}
signed main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
  return 0;
}
