#include <bits/stdc++.h>
using namespace std;
int main(void) {
  char A[20], B[20], a[20], b[20];
  int an, bn;
  scanf("%s %s", A, B);
  int big = 0;
  for (int i = 0; i < strlen(A); i++) big = max(big, A[i] - '0');
  for (int i = 0; i < strlen(B); i++) big = max(big, B[i] - '0');
  int la = strlen(A);
  int lb = strlen(B);
  for (int i = 0; i < la; i++) a[la - 1 - i] = A[i];
  for (int i = 0; i < lb; i++) b[lb - 1 - i] = B[i];
  big++;
  int sum[20];
  memset(sum, 0, sizeof sum);
  int answ = 0;
  for (int i = 0; i < min(la, lb); i++) {
    int x = sum[i];
    sum[i] = (sum[i] + (a[i] - '0') + (b[i] - '0')) % big;
    sum[i + 1] = (x + (a[i] - '0') + (b[i] - '0')) / big;
  }
  answ = min(la, lb);
  if (sum[answ] > 0) answ++;
  if (la > lb) {
    answ = lb;
    for (int j = lb; j < la; j++) {
      int x = sum[j];
      sum[j] = (sum[j] + (a[j] - '0')) % big;
      sum[j + 1] = (x + (a[j] - '0')) / big;
    }
    answ = la;
    if (sum[answ] > 0) answ++;
  } else if (lb > la) {
    answ = la;
    for (int j = la; j < lb; j++) {
      int x = sum[j];
      sum[j] = (sum[j] + (b[j] - '0')) % big;
      sum[j + 1] = (x + (b[j] - '0')) / big;
    }
    answ = lb;
    if (sum[answ] > 0) answ++;
  }
  cout << answ << endl;
  return 0;
}
