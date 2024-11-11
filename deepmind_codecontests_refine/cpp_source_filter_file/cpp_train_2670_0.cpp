#include <bits/stdc++.h>
using namespace std;
const int MAXX = 2e5 + 10, inf = 1e9 + 10;
int n;
vector<int> v;
bool flag;
struct Node {
  int pre, val, nxt;
} a[MAXX];
void Delete(int pos) {
  a[a[a[pos].pre].pre].nxt = pos;
  a[pos].pre = a[a[pos].pre].pre;
  ++a[pos].val;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  a[0].nxt = 1;
  for (int i = 1; i <= n; i++)
    cin >> a[i].val, a[i].pre = i - 1, a[i].nxt = i + 1;
  a[0].pre = -1, a[0].val = inf;
  for (int i = 1; i <= n; i++)
    while (a[i].pre != -1 && a[i].val == a[a[i].pre].val) Delete(i);
  for (int i = 0; a[i].nxt != n + 1; i = a[i].nxt) v.push_back(a[a[i].nxt].val);
  cout << v.size() << endl;
  for (auto x : v) cout << x << " ";
  return cout << endl, 0;
}
