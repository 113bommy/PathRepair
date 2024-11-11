#include <bits/stdc++.h>
using namespace std;
long long res;
int x, t;
int n;
int main() {
  scanf("%d", &n);
  t = 1;
  while (n--) {
    scanf("%d", &x);
    x--;
    res++;
    res += t * x;
    t++;
  }
  cout << res << endl;
  return 0;
}
