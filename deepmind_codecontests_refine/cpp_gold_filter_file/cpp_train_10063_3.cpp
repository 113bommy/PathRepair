#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct Node {
  int val, id;
  int dp, out;
} a[N];
bool cmp1(const Node& a, const Node& b) { return a.val < b.val; }
bool cmp2(const Node& a, const Node& b) { return a.id < b.id; }
int main() {
  int n, k;
  cin >> n >> k;
  memset(a, 0, sizeof a);
  for (int i = 1; i <= n; i++) {
    cin >> a[i].val;
    a[i].id = i;
  }
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    if (a[x].val < a[y].val) a[y].dp--;
    if (a[y].val < a[x].val) a[x].dp--;
  }
  sort(a + 1, a + 1 + n, cmp1);
  int cnt = 0;
  a[1].out = cnt + a[1].dp;
  for (int i = 2; i <= n; i++) {
    if (a[i].val == a[i - 1].val)
      a[i].out = cnt + a[i].dp;
    else {
      cnt = i - 1;
      a[i].out = cnt + a[i].dp;
    }
  }
  sort(a + 1, a + 1 + n, cmp2);
  cout << a[1].out;
  for (int i = 2; i <= n; i++) cout << " " << a[i].out;
  puts("");
}
