#include <bits/stdc++.h>
using namespace std;
int gcd(int f, int s) {
  if (s == 0)
    return f;
  else
    return gcd(s, f % s);
}
int const N = 600005;
long long const M = 998244353;
long double const ep = .000000000000000001;
map<long long, int> arr;
int go(int num) {
  int re = 0;
  for (int i = 30; i >= 0; i--) {
    int curr = arr[(1 << i)];
    int need = num / (1 << i);
    need = min(curr, need);
    num -= (1 << i) * need;
    re += need;
  }
  if (num == 0)
    return re;
  else
    return -1;
}
int main() {
  int a, q;
  cin >> a >> q;
  for (int i = 0; i < a; i++) {
    int t;
    scanf("%d", &t);
    arr[t]++;
  }
  while (q--) {
    int t;
    scanf("%d", &t);
    printf("%d\n", go(t));
  }
  return 0;
}
