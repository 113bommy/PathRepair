#include <bits/stdc++.h>
using namespace std;
template <typename T>
void show(const T& v) {
  cerr << v << ' ';
}
template <typename T1, typename... T2>
void show(const T1& first, const T2&... rest) {
  show(first);
  show(rest...);
}
template <typename F, typename S>
ostream& operator<<(ostream& os, const pair<F, S>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "{";
  typename vector<T>::const_iterator it;
  for (it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "}";
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v) {
  os << "[";
  typename set<T>::const_iterator it;
  for (it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}
template <typename F, typename S>
ostream& operator<<(ostream& os, const map<F, S>& v) {
  os << "[";
  typename map<F, S>::const_iterator it;
  for (it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << it->first << " = " << it->second;
  }
  return os << "]";
}
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long n, k;
  cin >> n >> k;
  vector<long long> arr(n + 1), preSum(n + 1);
  for (int i = 1; i <= n; i++) cin >> arr[i];
  sort(arr.begin() + 1, arr.end());
  for (int i = 1; i <= n; i++) preSum[i] = preSum[i - 1] + arr[i];
  long long num = -1, mx = INT_MIN;
  for (int i = n; i >= 1; i--) {
    long long lo = 1, hi = i - 1, ans = 0;
    while (lo <= hi) {
      long long mid = lo + (hi - lo) / 2;
      long long diff = ((i - mid) * arr[i]) - (preSum[i - 1] - preSum[mid - 1]);
      if (diff <= k) {
        hi = mid - 1;
        ans = (i - mid);
      } else
        lo = mid + 1;
    }
    if (ans >= mx) {
      mx = ans + 1;
      num = arr[i];
    }
  }
  cout << mx << " " << num << endl;
  return 0;
}
