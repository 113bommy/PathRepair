#include <bits/stdc++.h>
using namespace std;
struct node {
  int v, pos;
  friend bool operator<(node a1, node b) { return a1.v > b.v; }
} a[1110];
int an[1110];
int main() {
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i].v;
    a[i].pos = i;
  }
  sort(a, a + n);
  long long ans = 0;
  int to = 0;
  for (int i = 0; i < n; i++) {
    ans += i * a[i].v + 1;
    an[a[i].pos] = ++to;
  }
  cout << ans << endl;
  for (int i = 0; i < n - 1; i++) {
    cout << a[i].pos << " ";
  }
  cout << a[n - 1].pos << endl;
  return 0;
}
