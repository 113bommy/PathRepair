#include <bits/stdc++.h>
using namespace std;
long long b[7];
const long long M = 6 * 1e5 + 7;
struct data1 {
  long long x;
  long long val;
};
data1 a[M];
bool cmp(data1 u, data1 v) {
  return (u.x < v.x) || (u.x == v.x && u.val < v.val);
}
int main() {
  for (long long i = 1; i <= 6; i++) {
    cin >> b[i];
  }
  long long dem = 0;
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    for (long long j = 1; j <= 6; j++) {
      dem++;
      a[dem] = data1{x - b[j], i};
    }
  }
  sort(a + 1, a + dem + 1, cmp);
  long long r = 0;
  long long kq = 1e9;
  long long dem2 = 0;
  map<long long, long long> check;
  for (long long i = 1; i <= dem; i++) {
    for (; r < dem && dem2 != n;) {
      r++;
      check[a[r].val]++;
      if (check[a[r].val] == 1) {
        dem2++;
      }
    }
    if (dem2 != n) {
      break;
    }
    kq = min(kq, abs(a[r].x - a[i].x));
    check[a[i].val]--;
    if (check[a[i].val] == 0) {
      dem2--;
    }
  }
  cout << kq;
}
