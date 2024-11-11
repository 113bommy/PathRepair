#include <bits/stdc++.h>
using namespace std;
int p[3003];
int msp[3003];
int Read(int n) {
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i]);
  }
  return 0;
}
int GetInverseNumber(int n) {
  int sum = 0;
  int ptr1, ptr2;
  int end1, end2;
  int pos;
  for (int i = 1; i < n; i *= 2) {
    for (int j = 0; j < n; j += i + i) {
      ptr1 = j;
      ptr2 = j + i;
      end1 = min(j + i, n);
      end2 = min(j + i + i, n);
      pos = j;
      while (ptr1 < end1 && ptr2 < end2) {
        if (p[ptr1] > p[ptr2]) {
          sum += end1 - ptr1;
          msp[pos++] = p[ptr2++];
        } else {
          msp[pos++] = p[ptr1++];
        }
      }
      while (ptr1 < end1) {
        msp[pos++] = p[ptr1++];
      }
      while (ptr2 < end2) {
        msp[pos++] = p[ptr2++];
      }
      for (int k = j; k < end2; ++k) {
        p[k] = msp[k];
      }
    }
  }
  return sum;
}
int Process(int n) {
  int inverseNum = GetInverseNumber(n);
  if (inverseNum <= 0) {
    printf("%.6lf\n", 0.0);
  } else {
    if (inverseNum & 1) {
      printf("%.6lf\n", double((inverseNum - 1) * 2 + 1));
    } else {
      printf("%.6lf\n", double(inverseNum * 2));
    }
  }
  return 0;
}
int main() {
  int n;
  while (EOF != scanf("%d", &n)) {
    Read(n);
    Process(n);
  }
  return 0;
}
