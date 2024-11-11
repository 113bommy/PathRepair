#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int p[N];
int main() {
  int n, x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d", &x), p[x - 1] = i;
  }
  int ans = 0, c = 1;
  for (int i = 1; i < n; i++) {
    if (p[i] > p[i - 1]) {
      c++;
    } else
      c = 1;
    ans = max(c, ans);
  }
  cout << n - ans;
}
