#include <bits/stdc++.h>
using namespace std;
int MAX(long long int a, long long int b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}
int MIN(long long int a, long long int b) {
  if (a < b) {
    return a;
  } else {
    return b;
  }
}
int gcd(long long int a, long long int b) {
  long long int c;
  while (a != 0) {
    c = a;
    a = b % a;
    b = c;
  }
  return b;
}
int main() {
  int t;
  scanf("%d", &t);
  char c1;
  scanf("%c", &c1);
  int t1;
  for (t1 = 0; t1 < t; t1++) {
    string a[20];
    int i;
    for (i = 0; i < 8; i++) {
      cin >> a[i];
    }
    int j;
    int x1[2];
    int y1[2];
    int no = 0;
    for (i = 0; i < 8; i++) {
      for (j = 0; j < 8; j++) {
        if (a[i][j] == 'K') {
          x1[no] = i;
          y1[no] = j;
          no++;
        }
      }
    }
    if (x1[0] % 2 == x1[1] % 2 && y1[0] % 2 == y1[1] % 2) {
      if ((abs(x1[0] - x1[1]) % 4 == 0) && abs(y1[0] - y1[1] % 4 == 0)) {
        printf("YES\n");
      } else {
        printf("NO\n");
      }
    } else {
      printf("NO\n");
    }
    char c;
    if (t1 != t - 1) {
      scanf("%c", &c);
    }
  }
  return 0;
}
