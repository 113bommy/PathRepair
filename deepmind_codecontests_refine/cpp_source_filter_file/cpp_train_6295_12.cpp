#include <bits/stdc++.h>
const long long INF = 1e9;
const long long lINF = 1e18;
using namespace std;
int sum1[222222], sum2[222222], sum3[222222];
const int N = 222222;
int n, a[222222], b[222222], n1[222222], n2[222222], res[222222];
int get1(int r) {
  int result = 0;
  for (; r >= 0; r = (r & (r + 1)) - 1) result += sum1[r];
  return result;
}
int get2(int r) {
  int result = 0;
  for (; r >= 0; r = (r & (r + 1)) - 1) result += sum2[r];
  return result;
}
int get3(int r) {
  int result = 0;
  for (; r >= 0; r = (r & (r + 1)) - 1) result += sum3[r];
  return result;
}
void inc1(int i, int delta) {
  for (; i < N; i = (i | (i + 1))) sum1[i] += delta;
}
void inc2(int i, int delta) {
  for (; i < N; i = (i | (i + 1))) sum2[i] += delta;
}
void inc3(int i, int delta) {
  for (; i < N; i = (i | (i + 1))) sum3[i] += delta;
}
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    inc3(i, 1);
    inc2(i, 1);
    inc1(i, 1);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    n1[i] = get1(a[i]);
    inc1(a[i], -1);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
    n2[i] = get2(b[i]);
    inc2(b[i], -1);
  }
  for (int i = n - 1, j = 0; i >= 0; i--) {
    res[i] = (n1[i] + n2[i] + j) % (n - i);
    if (n1[i] + n2[i] + j >= n - i)
      j = 1;
    else
      j = 0;
  }
  for (int i = 0; i < n; i++) {
    int l = 0, r = n;
    while (r - l > 1) {
      int mid = (r + l) / 2;
      if (get3(mid) > res[i]) {
        r = mid;
      } else
        l = mid;
    }
    printf("%d ", l);
    inc3(res[i] + 1, -1);
  }
  return 0;
}
