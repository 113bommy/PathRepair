#include <bits/stdc++.h>
using namespace std;
long long s[101000];
int N;
int lowbit(int x) { return x & -x; }
long long sum(int x) {
  long long re = 0;
  for (int i = x; i; i -= lowbit(i)) re += s[i];
  return re;
}
void add(int x, long long c) {
  for (int i = x; i <= N; i += lowbit(i)) s[i] += c;
}
int a[101000];
int r[101000];
bool cmp(int x, int y) { return a[x] == a[y] ? x < y : a[x] < a[y]; }
int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) scanf("%d", &a[i]), r[i] = i;
  sort(r + 1, r + 1 + N, cmp);
  for (int i = 1; i <= N; i++) add(i, 1);
  int j = 0;
  long long ans = 0;
  for (int i = 1; i <= N;) {
    int len = 0;
    for (int k = i; k <= N && a[r[k]] == a[r[i]]; k++, len++)
      ;
    int key = lower_bound(r + i, r + i + len, j) - r;
    if (key != i)
      (ans += sum(N) - sum(j) + sum(r[key - 1])), j = r[key - 1];
    else
      ans += (sum(r[i + len - 1]) - sum(j)), j = r[i + len - 1];
    for (int k = i; k < i + len; k++) add(r[k], -1);
    i += len;
  }
  cout << ans << endl;
}
