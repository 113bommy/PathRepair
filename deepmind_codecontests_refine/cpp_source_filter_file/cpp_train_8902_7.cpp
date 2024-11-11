#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
char str[N];
map<int, int> a;
map<long long, int> bj;
int main() {
  int n;
  bj.clear();
  scanf("%d", &n);
  scanf("%s", str);
  long long int w = 1;
  int sum = 0;
  bj[1] = 1;
  int gh;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &gh);
    a[i] = gh;
  }
  while (1) {
    if (str[w] == '>') {
      w += a[w];
    } else {
      w -= a[w];
    }
    if (w > n || w < 1 || sum == n) {
      break;
    }
    if (bj[w]) {
      puts("INFINITE");
      return 0;
    } else {
      bj[w] = 1;
      sum++;
    }
  }
  puts("FINITE");
  return 0;
}
