#include <bits/stdc++.h>
using namespace std;
char a[100], b[100];
int main() {
  int a[10];
  int b[10];
  a[0] = 1;
  a[1] = 1;
  a[2] = 2;
  a[3] = 7;
  a[4] = 5;
  int x;
  int cnt = 100000000;
  for (int i = 0; i < 5; i++) {
    scanf("%d", &x);
    cnt = min(cnt, x / a[i]);
  }
  cout << cnt << endl;
  return 0;
}
