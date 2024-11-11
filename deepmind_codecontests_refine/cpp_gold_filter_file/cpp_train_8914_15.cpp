#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
const int maxm = 1e9 + 7;
int n;
int a[maxn], b[maxn], c[maxn], ans[maxn];
map<int, int> mp;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    b[i] = a[i];
  }
  queue<int> q;
  q.push(n);
  mp[a[n]] = n;
  for (int i = n; i >= 1; i--) {
    if (a[i] < a[q.back()]) {
      q.push(i);
      mp[a[q.back()]] = i;
    }
  }
  sort(b + 1, b + 1 + n);
  int num = unique(b + 1, b + n + 1) - b;
  int p = 0;
  for (int i = 1; i <= num - 1; i++) {
    int j = b[i];
    if (!mp[j])
      mp[j] = p;
    else {
      swap(mp[j], p);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (i >= mp[a[i]])
      printf("-1 ");
    else
      printf("%d ", mp[a[i]] - i - 1);
  }
}
