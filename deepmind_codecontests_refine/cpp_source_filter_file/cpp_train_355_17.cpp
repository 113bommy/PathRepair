#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10;
const int INF = 1e9;
const int MOD = 1e9 + 7;
int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }
int St[MAXN], top;
int main() {
  int n;
  scanf("%d", &n);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    while (top >= 2 && St[top - 2] > St[top - 1] && St[top - 1] < t) {
      ans += min(St[top - 2], t);
      top--;
    }
    St[top++] = t;
  }
  sort(St, St + top);
  for (int i = 0; i < top - 2; i++) {
    ans += St[i];
  }
  cout << ans << endl;
  return 0;
}
