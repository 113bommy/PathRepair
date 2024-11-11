#include <bits/stdc++.h>
using namespace std;
int n, p[3];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    p[a % 3]++;
  }
  if (p[0] > p[1] && p[0] > p[2]) puts("chest");
  if (p[1] > p[0] && p[1] > p[2]) puts("biceps");
  if (p[2] > p[1] && p[2] > p[0]) puts("back");
  return 0;
}
