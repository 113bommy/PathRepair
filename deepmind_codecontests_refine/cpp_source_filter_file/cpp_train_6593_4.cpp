#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int MN = 1000111;
int a[MN], b[MN];
char s1[1011], s2[1011];
bool win(char a, char b) {
  if (a == 'R' && b == 'S') return true;
  if (a == 'S' && b == 'P') return true;
  if (a == 'P' && b == 'R') return true;
  return false;
}
int main() {
  int n;
  scanf("%d\n", &n);
  gets(s1);
  gets(s2);
  int n1 = strlen(s1), n2 = strlen(s2);
  int i = 0, j = 0;
  for (int turn = 0, _a = (n1 * n2); turn < _a; turn++) {
    if (win(s1[i], s2[j]))
      a[turn] = a[turn - 1] + 1;
    else
      a[turn] = a[turn - 1];
    if (win(s2[j], s1[i]))
      b[turn] = b[turn - 1] + 1;
    else
      b[turn] = b[turn - 1];
    i++;
    j++;
    if (i >= n1) i = 0;
    if (j >= n2) j = 0;
  }
  int sl = n / (n1 * n2);
  int A = a[n1 * n2] * sl, B = b[n1 * n2] * sl;
  n -= sl * (n1 * n2);
  A += a[n];
  B += b[n];
  swap(A, B);
  printf("%d %d\n", A, B);
  return 0;
}
