#include <bits/stdc++.h>
using namespace std;
struct node {
  int a, b, c, d;
  void write() { cout << a << ' ' << b << ' ' << c << ' ' << d << endl; }
};
vector<node> ans;
int a[1005], b[1005], p[1005], q[1005];
int ra[1005], rb[1005], rp[1005], rq[1005];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> rq[i];
    q[rq[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    cin >> rp[i];
    p[rp[i]] = i;
  }
  for (int i = 1; i <= n; i++) a[i] = ra[i] = b[i] = rb[i] = i;
  for (int i = 1; i <= n; i++) {
    if (a[i] == p[i] && b[i] == q[i]) continue;
    ans.push_back(node{i, ra[p[i]], rb[q[i]], i});
    int t1 = a[i], t2 = b[i];
    swap(a[i], a[ra[p[i]]]);
    swap(b[i], b[rb[q[i]]]);
    swap(ra[p[i]], ra[t1]);
    swap(rb[q[i]], rb[t2]);
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) ans[i].write();
  cout << endl;
}
