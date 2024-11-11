#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
int n, c;
int a[10000];
int b[10000];
void solution() {
  scanf("%d %d", &n, &c);
  for (int i = 0, _n = (n); i < _n; ++i) scanf("%d %d", a + i, b + i);
  int ret = 0;
  for (int first = 0; first <= 500000; first++) {
    long long days = n;
    for (int i = 0, _n = (n); i < _n; ++i)
      days += ((long long)a[i]) * first / b[i];
    if (days == c) ret++;
  }
  cout << ret << endl;
}
int main() {
  solution();
  return 0;
}
