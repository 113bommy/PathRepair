#include <bits/stdc++.h>
template <class T>
typename T::value_type arr_sum(const T& v, int n) {
  typename T::value_type sum = 0;
  for (int i = 0; i < n; ++i) sum += v[i];
  return sum;
}
template <class T>
long long arr_count(const T& v, int n, int t) {
  long long count = 0;
  for (int i = 0; i < n; ++i) count += (v[i] == t);
  return count;
}
template <class T>
typename T::value_type arr_maxi(const T& v, int n) {
  typename T::value_type maxi = 0;
  for (int i = 1; i < n; ++i)
    if (v[maxi] < v[i]) maxi = i;
  return maxi;
}
template <class T>
typename T::value_type arr_mini(const T& v, int n) {
  typename T::value_type mini = 0;
  for (int i = 1; i < n; ++i)
    if (v[mini] > v[i]) mini = i;
  return mini;
}
template <class T>
typename T::value_type arr_max(const T& v, int n) {
  typename T::value_type max = v[0];
  for (int i = 1; i < n; ++i)
    if (max < v[i]) max = v[i];
  return max;
}
template <class T>
typename T::value_type arr_min(const T& v, int n) {
  typename T::value_type min = v[0];
  for (int i = 1; i < n; ++i)
    if (min > v[i]) min = v[i];
  return min;
}
using namespace std;
long long n;
long long k;
const long double eps = 0.00001;
int f(long long m) {
  m = 2 * m + 1;
  long double res = (long double)(m - 1) / 2 + ((long long)1 << k) - 1;
  if (abs(res - (long double)n / m) < eps) {
    return 0;
  }
  if (res - (long double)n / m >= eps) {
    return 1;
  }
  return -1;
}
long long bsearch_answer(long long l, long long r, int (*f)(long long t)) {
  while (l < r) {
    long long t = (l + r) / 2;
    if (!f(t)) {
      l = t;
      break;
    } else if (f(t) > 0) {
      r = t;
    } else {
      l = t + 1;
    }
  }
  return l;
}
int main() {
  cin >> n;
  vector<long long> res;
  for (k = 0; k <= 62; ++k) {
    long long l = bsearch_answer(0, 1000000000, f);
    if (f(l) == 0) {
      res.push_back((2 * l + 1) << k);
    }
  }
  if (res.size() == 0) {
    cout << -1 << endl;
    return 0;
  }
  sort(res.begin(), res.end());
  for (auto i : res) {
    cout << i << endl;
  }
}
