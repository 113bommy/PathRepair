#include <bits/stdc++.h>
using namespace std;
int que1[100005], que2[100005];
long long a[100005], b[100005];
int main() {
  long long n, k, i;
  while (cin >> n >> k) {
    long long sum = 0;
    if (n == 0) cout << "End of line";
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      b[i] = a[i];
      sum += a[i];
    }
    if (k > sum) {
      cout << "-1" << endl;
      continue;
    }
    if (k == sum) {
      cout << endl;
      continue;
    }
    sort(b, b + n);
    long long num = 0;
    int kk = 0;
    while (k >= 0) {
      long long minn = 0x7fffffff;
      long long cnt = 0;
      minn = b[kk++] - num;
      cnt = n - kk + 1;
      while (b[kk] == b[kk - 1] && k < n) {
        kk++;
      }
      if (cnt == 0) {
        if (n != 0 && k != 0) cout << -1;
        break;
      }
      if (minn * cnt > k) {
        long long t = k / cnt;
        for (i = 0; i < n; i++) {
          if (a[i] - num > 0) {
            a[i] -= t;
          }
        }
        k -= (cnt * t);
        int l = 0, ll = 0;
        for (i = 0; i < n; i++) {
          if (k > 0 && a[i] - num > 0) {
            a[i]--;
            k--;
            if (a[i] - num > 0) {
              que2[ll++] = i;
            }
          } else if (a[i] - num > 0) {
            que1[l++] = i;
          }
        }
        for (i = 0; i < l; i++) cout << que1[i] + 1 << " ";
        for (i = 0; i < ll; i++) cout << que2[i] + 1 << " ";
        break;
      } else {
        k -= (minn * cnt);
        num += minn;
      }
    }
    cout << endl;
  }
}
