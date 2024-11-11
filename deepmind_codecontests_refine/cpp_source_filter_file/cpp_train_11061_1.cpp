#include <bits/stdc++.h>
using namespace std;
template <class T>
bool uin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool uax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
long long a[2 * 100002], b[2 * 100002];
long long p1[2 * 100002], p2[2 * 100002];
int main() {
  long long n;
  cin >> n;
  for (long long i = 0; i < (long long)(n); ++i) {
    cin >> a[i];
    p1[a[i]] = i;
  }
  for (long long i = 0; i < (long long)(n); ++i) {
    cin >> b[i];
    p2[b[i]] = i;
  }
  map<long long, long long> m1, m2;
  for (long long i = 1; i <= (long long)(n); ++i) {
    long long q1 = (p1[i] - p2[i] + n) % n;
    long long q2 = (p2[i] - p1[i] + n) % n;
    auto it1 = m1.find(q1);
    auto it2 = m2.find(q2);
    if (it1 == m1.end())
      m1.insert(make_pair(q1, 1));
    else
      m1[q1]++;
    if (it2 == m2.end())
      m2.insert(make_pair(q2, 1));
    else
      m2[q2]++;
  }
  long long ma = 0;
  for (long long i = 1; i <= (long long)(n); ++i) ma = max(ma, m1[i]);
  for (long long i = 1; i <= (long long)(n); ++i) ma = max(ma, m2[i]);
  cout << ma;
}
