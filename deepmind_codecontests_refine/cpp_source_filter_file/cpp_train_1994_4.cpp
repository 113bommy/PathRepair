#include <bits/stdc++.h>
using namespace std;
const int maxn = 111;
int n;
int a[maxn];
bool check(int d) {
  map<int, int> t;
  for (int i = 0; i < n; i++) {
    t[a[i] + 1000]++;
    t[a[i] - d + 1000]++;
    t[a[i] + d + 1000]++;
  }
  for (auto p : t)
    if (p.second == n) return 1;
  return 0;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  bool flag = 1;
  for (int i = 0; i < n; i++)
    if (a[i] != a[1]) flag = 0;
  if (flag || n == 1) return 0 * puts("0");
  for (int D = 0; D <= 201; D++) {
    if (check(D)) return 0 * printf("%d\n", D);
  }
  return 0 * puts("-1");
  return 0;
}
