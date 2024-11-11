#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[501][501];
long long result;
long long num;
long long tong;
long long vitri, hang, cot;
long long checkhang() {
  long long i, j;
  long long temptong;
  long long coketqua;
  long long tempvitri;
  for (i = 0; i < n; i++) {
    coketqua = 1;
    temptong = 0;
    for (j = 0; j < n; j++) {
      temptong = temptong + a[i][j];
      if (a[i][j] == 0) {
        coketqua = 0;
        vitri = i;
        break;
      }
    }
    if (coketqua == 1) {
      if (tong == 0)
        tong = temptong;
      else {
        if (temptong != tong) return -1;
      }
    }
  }
}
long long checkcot() {
  long long i, j;
  long long temptong;
  long long coketqua;
  for (j = 0; j < n; j++) {
    coketqua = 1;
    temptong = 0;
    for (i = 0; i < n; i++) {
      temptong = temptong + a[i][j];
      if (a[i][j] == 0) {
        coketqua = 0;
        break;
      }
    }
    if (coketqua == 1) {
      if (tong == 0)
        tong = temptong;
      else {
        if (temptong != tong) return -1;
      }
    }
  }
  return 1;
}
int checkcheo1() {
  long long i, j;
  long long temptong;
  long long coketqua;
  temptong = 0;
  for (i = 0; i < n; i++) {
    temptong = temptong + a[i][i];
    if (a[i][i] == 0) {
      return 1;
    }
  }
  if (tong == 0)
    tong = temptong;
  else {
    if (temptong != tong) return -1;
  }
  return 1;
}
long long checkcheo2() {
  long long i, j;
  long long temptong;
  long long coketqua;
  temptong = 0;
  for (i = n - 1; i >= 0; i--) {
    temptong = temptong + a[n - 1 - i][i];
    if (a[n - 1 - i][i] == 0) {
      return 1;
    }
  }
  if (tong == 0)
    tong = temptong;
  else {
    if (temptong != tong) return -1;
  }
  return 1;
}
void getResult() {
  long long j;
  long long temptong = 0;
  for (j = 0; j < n; j++) {
    temptong = temptong + a[vitri][j];
  }
  result = tong - temptong;
  a[hang][cot] = result;
}
void solve() {
  result = -1;
  tong = 0;
  if (checkhang() == -1) {
    result = -1;
    return;
  }
  if (checkcot() == -1) {
    result = -1;
    return;
  }
  if (checkcheo1() == -1) {
    result = -1;
    return;
  }
  if (checkcheo2() == -1) {
    result = -1;
    return;
  }
  getResult();
  if (checkhang() == -1) {
    result = -1;
    return;
  }
  if (checkcot() == -1) {
    result = -1;
    return;
  }
  if (checkcheo1() == -1) {
    result = -1;
    return;
  }
  if (checkcheo2() == -1) {
    result = -1;
    return;
  }
}
int main() {
  int i, j;
  while (scanf("%I64d", &n) > 0) {
    num = 0;
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        scanf("%I64d", &a[i][j]);
        if (a[i][j] == 0) {
          hang = i;
          cot = j;
        }
      }
    }
    if (n == 1) {
      if (a[0][0] != 0)
        printf("-1\n");
      else
        printf("1\n");
    } else {
      solve();
      if (result <= 0) result = -1;
      printf("%I64d\n", result);
    }
  }
  return 0;
}
