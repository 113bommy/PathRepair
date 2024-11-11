#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[100005], b[100005], c[100005];
  int A[32], B[32], C[32];
  scanf("%s %s %s", a, b, c);
  int l1 = strlen(a);
  int l2 = strlen(b);
  int l3 = strlen(c);
  for (int i = 0; i < l1; i++) {
    A[a[i] - 'a']++;
  }
  for (int i = 0; i < l3; i++) {
    B[b[i] - 'a']++;
  }
  for (int i = 0; i < l3; i++) {
    C[c[i] - 'a']++;
  }
  int mx = 0;
  int cnt1 = 0, cnt2 = 0, y = 0, z = 0;
  for (int i = 0;; i++) {
    int fl = 0;
    for (int j = 0; j < 30; j++) {
      if (A[j] < B[j] * i) {
        fl = 1;
        break;
      }
    }
    if (fl) {
      break;
    }
    y = i;
    int m = 1000000000;
    for (int j = 0; j < 30; j++) {
      if (C[j] != 0) {
        int x = (A[j] - (i * B[j])) / C[j];
        m = min(m, x);
      }
    }
    if (mx < m + i) {
      mx = m + i;
      cnt1 = i;
      cnt2 = m;
    }
  }
  for (int i = 0; i < cnt1; i++) {
    printf("%s", b);
  }
  for (int i = 0; i < cnt2; i++) {
    printf("%s", c);
  }
  for (int i = 0; i < 30; i++) {
    A[i] -= (B[i] * cnt1);
    A[i] -= (C[i] * cnt2);
    for (int j = 0; j < A[i]; j++) {
      printf("%c", i + 'a');
    }
  }
}
