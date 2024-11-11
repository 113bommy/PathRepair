#include <bits/stdc++.h>
using namespace std;
const int MAX = 10000000;
int findMax(int* hh, int* mm, int count, int x) {
  int max = -1, i_max = -1;
  for (int i = 0; i < count; ++i) {
    if (hh[i] <= x && max < mm[i]) {
      i_max = i;
      max = mm[i];
    }
  }
  if (max == -1) {
    return x;
  }
  hh[i_max] = MAX;
  return max + x;
}
int main() {
  int n, x;
  int h11[2000], m1[2000];
  int h21[2000], m2[2000];
  int h12[2000], h22[2000];
  int i1 = 0, i2 = 0;
  cin >> n >> x;
  for (int i = 0; i < n; ++i) {
    int t, h, m;
    cin >> t >> h >> m;
    if (t == 0) {
      h11[i1] = h;
      h12[i1] = h;
      m1[i1++] = m;
    } else {
      h21[i2] = h;
      h22[i2] = h;
      m2[i2++] = m;
    }
  }
  int count1, count2;
  int x1, x2;
  count1 = count2 = 0;
  x1 = x2 = x;
  int x_new = x, temp = x;
  while (count1 <= n) {
    x_new = findMax(h11, m1, i1, x_new);
    if (temp == x_new) {
      break;
    } else {
      count1++;
    }
    temp = x;
    x_new = findMax(h21, m2, i2, x_new);
    if (x_new == temp) {
      break;
    } else {
      count1++;
    }
    temp = x_new;
  }
  temp = x_new = x;
  while (count2 <= n) {
    x_new = findMax(h22, m2, i2, x_new);
    if (temp == x_new) {
      break;
    } else {
      count2++;
    }
    temp = x_new;
    x_new = findMax(h12, m1, i1, x_new);
    if (x_new == temp) {
      break;
    } else {
      count2++;
    }
    temp = x_new;
  }
  cout << max(count1, count2);
  return 0;
}
