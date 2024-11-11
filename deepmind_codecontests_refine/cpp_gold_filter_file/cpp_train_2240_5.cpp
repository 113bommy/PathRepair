#include <bits/stdc++.h>
using namespace std;
int tree[1000005], a[1000005], b[1000005], n, tr[1000005], drr[1000005],
    dr[1000005];
void update(int index) {
  while (index <= n + 1) {
    tree[index]++;
    index += (index & (-index));
  }
}
int query(int index) {
  int sum = 0;
  while (index > 0) {
    sum += tree[index];
    index -= (index & (-index));
  }
  return sum;
}
void up(int index) {
  while (index <= n + 1) {
    tr[index]++;
    index += (index & (-index));
  }
}
int q(int index) {
  int sum = 0;
  while (index > 0) {
    sum += tr[index];
    index -= (index & (-index));
  }
  return sum;
}
int main() {
  int i, an, ans;
  cin >> n;
  for (i = 1; i <= n; ++i) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b + 1, b + n + 1);
  for (i = 1; i <= n; ++i) {
    an = lower_bound(b + 1, b + 1 + n, a[i]) - b;
    a[i] = an;
  }
  update(a[1]);
  for (i = 2; i <= n; ++i) {
    ans = query(a[i]);
    an = i - 1;
    an = an - ans;
    update(a[i]);
    drr[i] = an;
  }
  for (i = 1; i <= n / 2; ++i) {
    int temp = a[i];
    a[i] = a[n + 1 - i];
    a[n + 1 - i] = temp;
  }
  up(a[1]);
  for (i = 2; i <= n; ++i) {
    ans = q(a[i]);
    up(a[i]);
    dr[n - i + 1] = ans;
  }
  long long int sum = 0;
  for (i = 2; i < n; ++i) {
    sum += (drr[i] * 1ll * dr[i]);
  }
  cout << sum << endl;
}
