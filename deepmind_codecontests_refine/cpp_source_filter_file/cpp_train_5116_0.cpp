#include <bits/stdc++.h>
using namespace std;
vector<long long> vec;
long long f(long long m) {
  int v = 0;
  vector<long long> copy;
  for (int i = 0; i < m; i++) {
    copy.push_back(vec[i]);
  }
  sort(copy.begin(), copy.end());
  for (int i = copy.size() - 1; i >= 0; i -= 2) {
    v += copy[i];
  }
  return v;
}
int main() {
  long long n, h, a;
  cin >> n >> h;
  for (int i = 0; i < n; i++) {
    cin >> a;
    vec.push_back(a);
  }
  long long l = 1;
  long long r = n;
  long long m = 0;
  while (l + 1 < r) {
    m = (l + r) / 2;
    if (f(m) > h) {
      r = m;
    }
    if (f(m) <= h) {
      l = m;
    }
  }
  sort(vec.begin(), vec.end());
  long long v = 0;
  for (int i = vec.size() - 1; i >= 0; i -= 2) {
    v += vec[i];
  }
  if (v <= h) {
    cout << n;
    return 0;
  }
  cout << l;
  return 0;
}
