#include <bits/stdc++.h>
using namespace std;
long long c[100001];
int binarys(vector<long long> a, int l, int r, int x) {
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (a[m] == x) return m;
    if (a[m] < x)
      l = m + 1;
    else
      r = m - 1;
  }
  return -1;
}
vector<int> a(300001), b(300001);
vector<int> v1, v2;
bool comp2(int x, int y) { return a[x] < a[y]; }
bool comp1(int x, int y) { return b[x] > b[y]; }
int main() {
  long long n, m = 0, i, flag = 1, ans = 0, x = 0, r = 0, ta = 4294967295, tb,
               j = 0, k = 0, t;
  cin >> t >> n >> m;
  k = t - n;
  if (k > 0) {
    if (k - m > 0)
      cout << "+\n";
    else if (k - m <= 0)
      cout << "?\n";
  } else if (k < 0) {
    if (k + m < 0)
      cout << "-\n";
    else if (k + m >= 0)
      cout << "?\n";
  } else {
    if (m)
      cout << "?\n";
    else
      cout << "0\n";
  }
}
