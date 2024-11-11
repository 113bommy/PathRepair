#include <bits/stdc++.h>
using namespace std;
long long a[200005], b[200005], ans[200005];
pair<int, int> s[200005];
int main() {
  int n, m;
  cin >> n >> m;
  int top = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &a[i]);
    b[i] = a[i];
  }
  for (int i = 0; i < m; i++) {
    int t, r;
    scanf("%d%d", &t, &r);
    while (top && s[top - 1].second <= r) top--;
    s[top].first = t;
    s[top].second = r;
    top++;
  }
  sort(b + 1, b + s[0].second + 1);
  int l = 1, r = s[0].second;
  for (int i = 0; i < top - 1; i++) {
    for (int j = s[i].second; j > s[i + 1].second; j--) {
      if (s[i].first == 1) {
        a[j] = b[r--];
      } else
        a[j] = b[l++];
    }
  }
  for (int i = s[top - 1].second; i >= 1; i--) {
    if (s[top - 1].first == 1)
      a[i] = b[r--];
    else
      a[i] = b[l++];
  }
  for (int i = 1; i <= n; i++) {
    if (i != 1) printf(" ");
    printf("%I64d", a[i]);
  }
  cout << endl;
}
