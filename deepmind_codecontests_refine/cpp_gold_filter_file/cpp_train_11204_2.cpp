#include <bits/stdc++.h>
using namespace std;
const long maxn = 3e5 + 10;
bool mark[maxn];
int main() {
  long n;
  scanf("%ld", &n);
  long last = n, num = 0;
  printf("%ld ", 1);
  for (long i = 0; i < n; i++) {
    long x;
    scanf("%ld", &x);
    x--;
    mark[x] = 1;
    num++;
    while (mark[last - 1]) {
      last--;
      num--;
    }
    printf("%ld ", num + 1);
  }
}
