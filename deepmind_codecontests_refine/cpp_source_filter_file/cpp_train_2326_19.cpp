#include <bits/stdc++.h>
using namespace std;
int main() {
  int d;
  scanf("%d", &d);
  int n;
  scanf("%d", &n);
  long long ans = 0LL;
  int sum = 0;
  for (int i = (1); i <= (n); ++i) {
    int x;
    scanf("%d", &x);
    ans += sum ? n - sum : 0;
    sum = x;
  }
  cout << ans << endl;
  return 0;
}
