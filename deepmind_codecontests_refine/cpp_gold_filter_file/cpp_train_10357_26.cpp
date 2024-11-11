#include <bits/stdc++.h>
using namespace std;
inline void rdl(int &x) {
  x = 0;
  bool check = false;
  register int c;
  do {
    c = getchar();
    if (c == '-') check = true;
  } while (c < 48 || c > 57);
  for (; c > 47 && c < 58; c = getchar()) {
    x = (x << 1) + (x << 3) + c - 48;
  }
  if (check) x = -x;
}
inline void rd(int &x) {
  x = 0;
  bool check = false;
  register int c = getchar();
  for (; c < 48 || c > 57; c = getchar())
    ;
  for (; c > 47 && c < 58; c = getchar()) {
    x = (x << 1) + (x << 3) + c - 48;
  }
}
inline void pd(int x) {
  char c[11];
  bool check = false;
  int k = -1;
  if (x < 0) check = true, x = -x;
  do {
    c[++k] = x % 10 + 48;
    x /= 10;
  } while (x);
  if (check) c[++k] = '-';
  while (k >= 0) putchar(c[k--]);
  putchar('\n');
}
inline void pdl(long long int x) {
  char c[21];
  bool check = false;
  int k = -1;
  if (x < 0) check = true, x = -x;
  do {
    c[++k] = x % 10 + 48;
    x /= 10;
  } while (x);
  if (check) c[++k] = '-';
  while (k >= 0) putchar(c[k--]);
  putchar('\n');
}
bool cmp(int a, int b) { return a > b; }
int main() {
  char c[3];
  int i, j, k, l;
  scanf("%s", c);
  l = strlen(c);
  if (l == 1) {
    i = c[0] - '0';
    if (i == 0)
      printf("zero\n");
    else if (i == 1)
      printf("one\n");
    else if (i == 2)
      printf("two\n");
    else if (i == 3)
      printf("three\n");
    else if (i == 4)
      printf("four\n");
    else if (i == 5)
      printf("five\n");
    else if (i == 6)
      printf("six\n");
    else if (i == 7)
      printf("seven\n");
    else if (i == 8)
      printf("eight\n");
    else
      printf("nine\n");
  } else {
    if (c[0] == '1') {
      if (c[1] == '0')
        printf("ten\n");
      else if (c[1] == '1')
        printf("eleven\n");
      else if (c[1] == '2')
        printf("twelve\n");
      else if (c[1] == '3')
        printf("thirteen\n");
      else if (c[1] == '4')
        printf("fourteen\n");
      else if (c[1] == '5')
        printf("fifteen\n");
      else if (c[1] == '6')
        printf("sixteen\n");
      else if (c[1] == '7')
        printf("seventeen\n");
      else if (c[1] == '8')
        printf("eighteen\n");
      else
        printf("nineteen\n");
    } else if (c[0] == '0') {
      i = c[1] - '0';
      if (i == 0)
        printf("zero\n");
      else if (i == 1)
        printf("one\n");
      else if (i == 2)
        printf("two\n");
      else if (i == 3)
        printf("three\n");
      else if (i == 4)
        printf("four\n");
      else if (i == 5)
        printf("five\n");
      else if (i == 6)
        printf("six\n");
      else if (i == 7)
        printf("seven\n");
      else if (i == 8)
        printf("eight\n");
      else
        printf("nine\n");
    } else {
      i = c[0] - '0';
      if (i == 2)
        printf("twenty");
      else if (i == 3)
        printf("thirty");
      else if (i == 4)
        printf("forty");
      else if (i == 5)
        printf("fifty");
      else if (i == 6)
        printf("sixty");
      else if (i == 7)
        printf("seventy");
      else if (i == 8)
        printf("eighty");
      else
        printf("ninety");
      i = c[1] - '0';
      if (i == 0)
        printf("\n");
      else if (i == 1)
        printf("-one\n");
      else if (i == 2)
        printf("-two\n");
      else if (i == 3)
        printf("-three\n");
      else if (i == 4)
        printf("-four\n");
      else if (i == 5)
        printf("-five\n");
      else if (i == 6)
        printf("-six\n");
      else if (i == 7)
        printf("-seven\n");
      else if (i == 8)
        printf("-eight\n");
      else
        printf("-nine\n");
    }
  }
}
