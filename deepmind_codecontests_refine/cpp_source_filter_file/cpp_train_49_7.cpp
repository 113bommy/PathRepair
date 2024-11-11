#include <bits/stdc++.h>
using namespace std;
string l = "(((1-abs((t-", mid = ")))+abs((abs(t-", r = "))-1)))*";
string an1 = "", an2 = "";
int n;
string str(int x) {
  int A[25], l = 0;
  do {
    A[++l] = x % 10;
    x /= 10;
  } while (x);
  string res = "";
  for (int i = l; i >= 1; i--) res += (A[i] ^ '0');
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    an1 += '(';
    an2 += '(';
  }
  for (int i = 0, x, y, a; i < n; i++) {
    scanf("%d %d %d", &x, &y, &a);
    an1 += l + str(i) + mid + str(i) + r + str(x / 2) + ')';
    an2 += l + str(i) + mid + str(i) + r + str(y / 2) + ')';
    if (i != 0) an1 += ')', an2 += ')';
    if (i != n - 1) an1 += '+', an2 += '+';
  }
  cout << an1 << endl;
  cout << an2 << endl;
  return 0;
}
