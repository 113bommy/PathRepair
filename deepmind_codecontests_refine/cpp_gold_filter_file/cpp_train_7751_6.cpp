#include <bits/stdc++.h>
using namespace std;
int data[100005];
int temp[100005];
int forW[100005];
int backW[100005];
int cnt[100005];
int lo, hi, mid, id;
int search(int len, int x) {
  lo = 1, hi = len, mid, id = 0;
  while (lo <= hi) {
    mid = (lo + hi) / 2;
    if (x > temp[mid]) {
      id = mid;
      lo = mid + 1;
    } else
      hi = mid - 1;
  }
  temp[id + 1] = x;
  return id + 1;
}
int search2(int len, int x) {
  lo = 1, hi = len, mid, id = 0;
  while (lo <= hi) {
    mid = (lo + hi) / 2;
    if (x < temp[mid]) {
      id = mid;
      lo = mid + 1;
    } else
      hi = mid - 1;
  }
  temp[id + 1] = x;
  return id + 1;
}
int main() {
  int n, i, len = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &data[i]);
  int lis = 0;
  for (i = 0; i < n; i++) {
    if (temp[len] < data[i]) {
      temp[++len] = data[i];
      forW[i] = len;
    } else
      forW[i] = search(len, data[i]);
    lis = max(lis, forW[i]);
  }
  temp[0] = INT_MAX;
  len = 0;
  for (i = n - 1; i >= 0; i--) {
    if (temp[len] > data[i]) {
      temp[++len] = data[i];
      backW[i] = len;
    } else
      backW[i] = search2(len, data[i]);
  }
  for (i = 0; i < n; i++) {
    if (forW[i] + backW[i] - 1 == lis) cnt[forW[i]]++;
  }
  for (i = 0; i < n; i++)
    if (forW[i] + backW[i] - 1 != lis)
      printf("1");
    else {
      if (cnt[forW[i]] == 1)
        printf("3");
      else
        printf("2");
    }
  return 0;
}
