#include <bits/stdc++.h>
using namespace std;
void quick_sort(int a[], int left, int right) {
  int l = left, r = right, m = a[rand() % (r - l) + l];
  while (l < r) {
    while (a[l] < m) l++;
    while (a[r] > m) r--;
    if (l <= r) {
      int t = a[l];
      a[l] = a[r];
      a[r] = t;
      l++;
      r--;
    }
  }
  if (left < r) quick_sort(a, left, r);
  if (right > l) quick_sort(a, l, right);
}
int main() {
  int n, k, a[200000], size_a = 0, b[200000], size_b = 0, c[200000], size_c = 0,
                       min = 0, cnt_a = 0, cnt_b = 0;
  cin >> n >> k;
  while (n--) {
    int t[3];
    cin >> t[0] >> t[1] >> t[2];
    if (t[1] + t[2] == 2)
      c[size_c++] = t[0];
    else if (t[1])
      a[size_a++] = t[0];
    else if (t[2])
      b[size_b++] = t[0];
  }
  if (size_c > 1) quick_sort(c, 0, size_c - 1);
  if (size_a > 1) quick_sort(a, 0, size_a - 1);
  if (size_b > 1) quick_sort(b, 0, size_b - 1);
  int i = 0, j = 0, l = 0;
  for (;
       ((i < size_a && j < size_b) || l < size_c) && cnt_a < k && cnt_b < k;) {
    if (i < size_a && j < size_b) {
      if (l < size_c)
        if (a[i] + b[j] < c[l])
          min += a[i++] + b[j++];
        else
          min += c[l++];
      else
        min += a[i++] + b[j++];
    } else if (l < size_c) {
      min += c[l++];
    } else
      break;
    cnt_a++;
    cnt_b++;
  }
  for (; (i < size_a || l < size_c) && cnt_a < k;) {
    if (i < size_a) {
      if (l < size_c)
        if (a[i] < c[l])
          min += a[i++];
        else {
          min += c[l++];
          cnt_b++;
        }
      else
        min += a[i++];
    } else if (l < size_c) {
      min += c[l++];
      cnt_b++;
    } else
      break;
    cnt_a++;
  }
  for (; (j < size_b || l < size_c) && cnt_b < k;) {
    if (j < size_b) {
      if (l < size_c)
        if (b[j] < c[l])
          min += b[j++];
        else {
          min += c[l++];
          cnt_a++;
        }
      else
        min += b[j++];
    } else if (l < size_c) {
      min += c[l++];
      cnt_a++;
    } else
      break;
    cnt_b++;
  }
  if (cnt_a < k || cnt_b < k)
    cout << -1;
  else
    cout << min;
  return 0;
}
