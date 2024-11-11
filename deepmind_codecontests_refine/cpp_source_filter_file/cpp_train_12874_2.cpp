#include <bits/stdc++.h>
using namespace std;
int mod = 998244353;
const int valor = 5;
int inf = (1e9) + 7;
int main() {
  set<int> s;
  int n;
  scanf("%d", &n);
  int c = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    s.insert(x);
    if (x == 0) c--;
  }
  printf("%ld\n", s.size() - c);
}
