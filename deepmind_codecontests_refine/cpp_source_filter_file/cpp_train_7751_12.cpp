#include <bits/stdc++.h>
using namespace std;
int n, a[100005];
int dd[100005];
int b[100005], c[100005], l1[100005], l2[100005];
void DNT(int s[]) {
  int gt[100005];
  for (int i = 1; i <= n + 1; i++) gt[i] = 2e9 + 5;
  gt[1] = a[1];
  s[1] = 1;
  for (int i = 2; i <= n; i++) {
    s[i] = upper_bound(gt + 1, gt + n + 2, a[i]) - gt;
    gt[s[i]] = min(gt[s[i]], a[i]);
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  DNT(b);
  reverse(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) a[i] = -a[i];
  DNT(c);
  int Ma = *max_element(b + 1, b + n + 1);
  for (int i = 1; i <= n; i++)
    if (b[i] + c[n + 1 - i] - 1 == Ma) dd[b[i]]++;
  for (int i = 1; i <= n; i++) {
    if (b[i] + c[n + 1 - i] - 1 < Ma)
      cout << 1;
    else {
      if (dd[b[i]] == 1)
        cout << 3;
      else
        cout << 2;
    }
  }
}
