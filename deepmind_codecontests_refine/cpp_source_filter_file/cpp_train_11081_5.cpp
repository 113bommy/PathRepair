#include <bits/stdc++.h>
using namespace std;
char a[105];
char b[105];
char c[105];
char d[105];
struct node {
  char m;
  int l;
};
node num[5];
bool cmp(node a, node b) { return a.l < b.l; }
int main() {
  cin >> a;
  cin >> b;
  cin >> c;
  cin >> d;
  int A = strlen(a) - 2;
  int B = strlen(b) - 2;
  int C = strlen(c) - 2;
  int D = strlen(d) - 2;
  num[0].l = A;
  num[1].l = B;
  num[2].l = C;
  num[3].l = D;
  num[0].m = 'A';
  num[1].m = 'B';
  num[2].m = 'C';
  num[3].m = 'D';
  sort(num, num + 4, cmp);
  if (2 * num[0].l <= num[1].l) {
    if (num[3].l > 2 * num[2].l)
      printf("C\n");
    else
      printf("%c\n", num[0].m);
  } else if (num[3].l >= 2 * num[2].l) {
    if (2 * num[0].l <= num[1].l)
      printf("C\n");
    else
      printf("%c\n", num[3].m);
  } else
    printf("C\n");
  return 0;
}
