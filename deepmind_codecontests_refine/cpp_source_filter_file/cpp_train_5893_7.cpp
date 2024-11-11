#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, lmx[N], lmn[N], rmx[N], rmn[N];
int a[N];
stack<int> s1, s2, s3, s4;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  s1.push(0);
  s2.push(0);
  for (int i = 1; i <= n; i++) {
    while (s1.top() != 0 && a[s1.top()] >= a[i]) {
      s1.pop();
    }
    lmn[i] = s1.top();
    s1.push(i);
    while (s2.top() && a[s2.top()] <= a[i]) {
      s2.pop();
    }
    lmx[i] = s2.top();
    s2.push(i);
  }
  s3.push(n + 1);
  s4.push(n + 1);
  for (int i = n; i >= 1; i--) {
    while (s3.top() != n + 1 && a[s3.top()] >= a[i]) {
      s3.pop();
    }
    rmn[i] = s3.top();
    s3.push(i);
    while (s4.top() != n + 1 && a[s4.top()] <= a[i]) {
      s4.pop();
    }
    rmx[i] = s4.top();
    s4.push(i);
  }
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    ans += (long long)(i - lmx[i]) * (long long)(rmx[i] - i) * (long long)a[i];
    ans -= (long long)(i - lmn[i]) * (long long)(rmn[i] - i) * (long long)a[i];
  }
  printf("%I64d\n", ans);
  return 0;
}
