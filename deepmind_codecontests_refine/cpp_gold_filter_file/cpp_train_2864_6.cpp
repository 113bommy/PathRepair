#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
const int maxn = 100005;
int n, q;
int a[maxn], b[maxn], s[maxn], top;
int main() {
  int l, r;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (i) b[i] = abs(a[i] - a[i - 1]);
  }
  long long L[maxn], R[maxn];
  while (q--) {
    top = 1;
    cin >> l >> r;
    r--;
    b[0] = inf;
    s[0] = 0;
    for (int i = l; i <= r; i++) {
      while (top && b[s[top - 1]] <= b[i]) top--;
      L[i] = s[top - 1];
      s[top++] = i;
      if (L[i] == 0) L[i] = l - 1;
    }
    s[0] = 0;
    top = 1;
    for (int i = r; i >= l; i--) {
      while (top && b[s[top - 1]] < b[i]) top--;
      R[i] = s[top - 1];
      s[top++] = i;
      if (R[i] == 0) R[i] = r + 1;
    }
    long long ret = 0;
    for (int i = l; i <= r; i++) {
      ret += b[i] * (R[i] - i) * (i - L[i]);
    }
    cout << ret << endl;
  }
  return 0;
}
