#include <bits/stdc++.h>
using namespace std;
int is_prime(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
int find_min(int a[], int left, int right, int elems) {
  int low = 1, high = 1000000009, ans;
  while (low <= high) {
    int mid = (low + high) / 2;
    int taken = 0;
    for (int i = left; i <= right; i++) {
      if (a[i] <= mid) {
        taken++;
        i++;
      }
      if (taken >= elems) break;
    }
    if (taken >= elems) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return ans;
}
int main() {
  string s, t;
  int n, sone = 0, tone = 0;
  cin >> n;
  cin >> s;
  cin >> t;
  string sdiff = "";
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') sone++;
    if (t[i] == '1') tone++;
    if (s[i] != t[i]) sdiff += s[i];
  }
  if (sone != tone)
    cout << -1 << endl;
  else {
    int len = sdiff.length();
    int sum = 0;
    int maxm = 0;
    int minm = 0, ans1 = 0, ans2 = 0;
    for (int i = 0; i < len; i++) {
      if (sdiff[i] == '1')
        sum++;
      else
        sum--;
      minm = min(minm, sum);
      maxm = max(maxm, sum - minm);
      ans1 = maxm;
    }
    sum = 0;
    maxm = 0;
    minm = 0;
    for (int i = 0; i < len; i++) {
      if (sdiff[i] == '0')
        sum++;
      else
        sum--;
      minm = min(minm, sum);
      maxm = max(maxm, sum - minm);
      ans2 = maxm;
    }
    cout << max(ans1, ans2) << endl;
  }
}
