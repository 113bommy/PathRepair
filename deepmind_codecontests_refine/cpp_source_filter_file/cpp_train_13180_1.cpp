#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 50;
const int inf = 0x3f3f3f3f;
struct node {
  int l, r;
  int i;
} a[150];
int main() {
  int n;
  cin >> n;
  vector<deque<int> > b;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].l >> a[i].r;
    a[i].i = i;
  }
  for (int i = 0; i < n; ++i) {
    if (a[i].l == 0 && a[i].r != 0) {
      deque<int> b1;
      b1.push_back(i);
      b1.push_back(a[i].r);
      while (a[b1.back()].r != 0) {
        b1.push_back(a[b1.back()].r);
      }
      b.push_back(b1);
    }
    if (a[i].l == 0 && a[i].r == 0) {
      deque<int> b1;
      b1.push_back(i);
      b.push_back(b1);
    }
  }
  if (b.size() == 1) {
    for (int i = 1; i <= n; ++i) cout << a[i].l << " " << a[i].r << endl;
  } else {
    for (int i = b.size() - 1; i > 0; --i) {
      a[b[i].front()].l = b[i - 1].back();
      a[b[i - 1].back()].r = b[i].front();
    }
    for (int i = 1; i <= n; ++i) cout << a[i].l << " " << a[i].r << endl;
  }
}
