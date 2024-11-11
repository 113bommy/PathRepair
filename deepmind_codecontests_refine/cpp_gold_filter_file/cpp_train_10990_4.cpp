#include <bits/stdc++.h>
using namespace std;
int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
  int N, M;
  scanf("%d%d", &N, &M);
  int ans = 1;
  int K = month[N] - (7 - (M - 1));
  ans += K % 7 == 0 ? K / 7 : K / 7 + 1;
  cout << ans << endl;
  return 0;
}
