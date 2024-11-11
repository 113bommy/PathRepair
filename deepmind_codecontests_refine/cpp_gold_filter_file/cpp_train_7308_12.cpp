#include <bits/stdc++.h>
using namespace std;
const int N = 200200;
int n;
int p[N];
struct BIT {
  long long a[N];
  void add(int x, int v = 1) {
    for (; x < N; x += x & -x) {
      a[x] += v;
    }
  }
  long long query(int x) {
    long long ans = 0;
    for (; x > 0; x -= x & -x) {
      ans += a[x];
    }
    return ans;
  }
  int kth(int k) {
    int l = 1, r = N - 1;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (query(mid) >= k) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return l;
  }
};
BIT s1, s2;
int pos[N];
long long ss(long long x) { return x * (x + 1) / 2; }
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    pos[p[i]] = i;
  }
  long long sum = 0;
  long long nx = 0;
  for (int i = 1; i <= n; i++) {
    int x = pos[i];
    sum += x;
    s1.add(x);
    nx += i - s1.query(x);
    s2.add(x, x);
    int mm = (i + 1) / 2;
    int mid = s1.kth(mm);
    long long lp = s2.query(mid);
    long long rp = sum - lp;
    long long ans = nx + ((long long)mid * mm - lp) +
                    (rp - (long long)mid * (i - mm)) - ss(mm - 1) - ss(i - mm);
    cout << ans << " ";
  }
  cout << endl;
  return 0;
}
