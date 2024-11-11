#include <bits/stdc++.h>
using namespace std;
long long c[500005];
int n, k;
long long sum[500005];
long long Max, Min;
int check2(long long value) {
  long long s = 0;
  for (int i = n; i >= 1; i--) {
    if (c[i] > value) {
      s += c[i] - value;
    } else {
      break;
    }
  }
  if (s > k)
    return 0;
  else
    return 1;
}
long long find_max() {
  long long le = Min, re = Max, mid = (le + re) / 2;
  for (; le < re;) {
    if (check2(mid)) {
      re = mid;
      mid = (le + re) / 2;
    } else {
      le = mid + 1;
      mid = (le + re) / 2;
    }
  }
  return le;
}
int check1(long long value) {
  long long s = 0;
  for (int i = 1; i <= n; i++) {
    if (c[i] < value) {
      s += value - c[i];
    } else {
      break;
    }
  }
  if (s > k)
    return 0;
  else
    return 1;
}
long long find_min() {
  long long le = Min, re = Max, mid = (le + re) / 2;
  for (; le < re;) {
    if (check1(mid)) {
      le = mid;
      mid = (le + re) / 2;
    } else {
      re = mid - 1;
      mid = (le + re) / 2;
    }
    if (le == re - 1) {
      if (check1(re))
        return re;
      else
        return le;
    }
  }
  return le;
}
int main() {
  cin >> n >> k;
  Max = 0, Min = 10000000000;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &c[i]);
  }
  sort(c + 1, c + n + 1);
  Max = c[n];
  Min = c[1];
  c[0] = 0;
  sum[0] = 0;
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + c[i];
  long long ans1, ans2;
  ans1 = find_min();
  ans2 = find_max();
  if (ans2 >= ans1)
    cout << ans2 - ans1 << endl;
  else {
    long long s = 0;
    for (int i = n; i >= 1; i--) {
      if (c[i] > ans2) {
        s += c[i] - ans2;
      } else
        break;
    }
    for (int i = 1; i <= n; i++) {
      if (c[i] < ans2 && s >= 0) {
        s -= (ans2 - c[i]);
      } else
        break;
    }
    if (s % n == 0)
      cout << 0 << endl;
    else
      cout << 1 << endl;
  }
  return 0;
}
