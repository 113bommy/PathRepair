#include <bits/stdc++.h>
using namespace std;
vector<int> Positive, Negative;
int BSearchLBound(int a[], int b, int e, int val) {
  int m = (b + e) / 2;
  while (b < e) {
    if (e - b == 1 && a[e] > val)
      e = b;
    else if (e - b == 1)
      b = e;
    else if (a[m] >= val)
      e = m;
    else if (a[m] < val)
      b = m;
    m = (b + e) / 2;
  }
  return m;
}
int BSearchUBound(int a[], int b, int e, int val) {
  int m = (b + e) / 2;
  while (b < e) {
    if (e - b == 1 && a[b] < val)
      b = e;
    else if (e - b == 1)
      e = b;
    else if (a[m] > val)
      e = m;
    else if (a[m] <= val)
      b = m;
    m = (b + e) / 2;
  }
  return m;
}
int BSearchLBound(vector<int> a, int b, int e, int val) {
  int m = (b + e) / 2;
  while (b < e) {
    if (e - b == 1 && a[e] > val)
      e = b;
    else if (e - b == 1)
      b = e;
    else if (a[m] >= val)
      e = m;
    else if (a[m] < val)
      b = m;
    m = (b + e) / 2;
  }
  return m;
}
int BSearchUBound(vector<int> a, int b, int e, int val) {
  int m = (b + e) / 2;
  while (b < e) {
    if (e - b == 1 && a[b] < val)
      b = e;
    else if (e - b == 1)
      e = b;
    else if (a[m] > val)
      e = m;
    else if (a[m] <= val)
      b = m;
    m = (b + e) / 2;
  }
  return m;
}
struct Integer {
  int value, length, shifts;
  Integer(int v = 0) {
    value = v;
    int i;
    length = 0;
    for (i = 1; i <= value; i = i * 2) {
      length++;
    }
    shifts = 0;
  }
};
bool comp(Integer A, Integer B) {
  return A.value < B.value || (A.value == B.value && A.shifts < B.shifts);
}
int main() {
  int n, i, m;
  scanf("%d", &n);
  scanf("%d", &m);
  Integer a[n];
  for (i = 0; i < n; i++) {
    int input;
    scanf("%d", &input);
    a[i] = Integer(input);
  }
  int result = 1000000000;
  int j, k;
  for (k = 19 - 1; k >= 0; k--) {
    for (i = 0; i < n; i++) {
      if (a[i].length > k) {
        a[i].value = a[i].value >> 1;
        a[i].length--;
        a[i].shifts++;
      }
    }
    sort(a, a + n, comp);
    int consequtive_shifts = 0, similar = 0;
    for (i = 0; i < n; i++) {
      if (i == 0 || a[i].value != a[i - 1].value) {
        consequtive_shifts = a[i].shifts;
        similar = 1;
      } else {
        similar++;
        consequtive_shifts += a[i].shifts;
      }
      if (similar >= m && consequtive_shifts < result) {
        result = consequtive_shifts;
      }
    }
  }
  printf("%d", result);
  return 0;
}
