#include <bits/stdc++.h>
using namespace std;
long long comb3(int n) { return n * (n - 1) * (n - 2) / 6; }
int main() {
  long n, d;
  cin >> n >> d;
  vector<long> points(n);
  for (int i = int(0); i <= int(n - 1); i++) cin >> points[i];
  long long total = 0;
  for (int i = int(0); i <= int(n - 1); i++) {
    long target = points[i] + d;
    int beg = 0, end = n - 1;
    int mid = (beg + end) / 2;
    int res = 0;
    if (target < points[0]) res = -1;
    if (target > points[n - 1]) res = -2;
    if (res == 0) {
      while (beg < end) {
        if (points[mid] == target) {
          break;
        }
        if (points[mid] < target) {
          if (beg == mid) {
            if (mid + 1 < n && points[mid + 1] <= target) mid++;
            break;
          }
          beg = mid;
        }
        if (points[mid] > target) {
          end = mid - 1;
        }
        mid = (beg + end) / 2;
      }
      res = mid;
    }
    if (res == -2) res = n - 1;
    int inrange = res - i + 1;
    if (inrange >= 3) {
      total += comb3(inrange);
      if (i < n - 1) total -= comb3(inrange - 1);
    }
  }
  cout << total << '\n';
  return 0;
}
