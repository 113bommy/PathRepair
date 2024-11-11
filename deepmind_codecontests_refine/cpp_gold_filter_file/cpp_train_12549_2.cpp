#include <bits/stdc++.h>
using namespace std;
void __dbg() { cout << endl; }
template <typename Arg, typename... Args>
void __dbg(Arg A, Args... B) {
  cout << ' ' << A;
  __dbg(B...);
}
const int inf = INT_MAX;
const int ninf = INT_MIN;
const int mod = 1e9 + 7;
const int maxN = 1e6 + 2;
int main() {
  int n;
  scanf("%d", &n);
  int cnt0 = 0;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    if (x == 0) cnt0++;
  }
  if ((n > 1 && cnt0 != 1) || (n == 1 && cnt0 == 1)) {
    puts("NO");
  } else {
    puts("YES");
  }
  return 0;
}
