#include <bits/stdc++.h>
using namespace std;
set<long long> s;
set<long long>::iterator it;
vector<long long> v;
int n;
int x;
char a[100005];
int reverse(int x) {
  int temp = 0;
  while (x) {
    temp = temp * 10 + (x % 10);
    x /= 10;
  }
  return temp;
}
int main() {
  int i, j, t;
  scanf("%d", &x);
  while (x % 10 == 0) x /= 10;
  int y = reverse(x);
  int fg = 0;
  if (x != y) fg = 1;
  if (fg == 1)
    printf("NO\n");
  else
    printf("YES\n");
  return 0;
}
