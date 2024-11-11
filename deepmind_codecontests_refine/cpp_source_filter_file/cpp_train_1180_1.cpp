#include <bits/stdc++.h>
using namespace std;
const long double PI = acos((long double)-1);
int n, k;
long long r;
map<int, int> C;
int T[400010];
int main() {
  scanf("%d %d", &n, &k);
  for (int i = (0); i < (n); ++i) scanf("%d", &T[i]);
  int a = 0, b = 0;
  while (a < n) {
    while (b < n && (!b || C[T[b - 1]] != k)) ++C[T[b++]];
    if (C[T[b - 1]] == k) r += n - k + 1;
    --C[T[a++]];
  }
  cout << r << endl;
  return 0;
}
