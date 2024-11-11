#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 50;
struct A {
  int x, y, i;
} a[MAXN];
vector<int> v;
bool cmp(A a, A b) {
  if (a.x == b.x) return a.y > b.y;
  return a.x > b.x;
}
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x;
    a[i].i = i;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i].y;
  }
  sort(a + 1, a + n + 1, cmp);
  v.push_back(a[1].i);
  if (n % 2 == 0) {
    v.push_back(a[n].i);
  }
  for (int i = 2; i <= n; i += 2) {
    if (a[i].y >= a[i + 1].y) {
      v.push_back(a[i].i);
    } else
      v.push_back(a[i + 1].i);
  }
  int l = v.size();
  cout << l << endl;
  for (int i = 0; i < l; i++) {
    cout << v[i] << ' ';
  }
  cout << endl;
}
