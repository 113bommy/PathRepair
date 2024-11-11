#include <bits/stdc++.h>
using namespace std;
const long long inf = LONG_MAX;
const long long arr = 1000000;
long long a[4][10000];
bool comp(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first == b.first)
    return a.second < b.second;
  else
    return a.first < b.first;
}
int main(void) {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long j = 0, t = 0;
  long long ansl = 0, ansr = 0;
  for (int i = 0; i < n; i++) {
    if (j < i) {
      j = i;
      t = 0;
    }
    while (j < n) {
      long long temp = t + !a[j];
      if (temp > k) break;
      t += !a[j];
      j++;
    }
    if (j - i > ansr - ansl) ansl = i, ansr = j;
    if (t > 0) t -= !a[i];
  }
  for (int i = ansl; i <= ansr; i++) a[i] = 1;
  cout << ansr - ansl << '\n';
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  return 0;
}
