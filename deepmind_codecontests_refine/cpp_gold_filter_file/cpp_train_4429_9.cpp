#include <bits/stdc++.h>
const unsigned long long inf = 1LL << 61;
const double eps = 1e-5;
using namespace std;
priority_queue<int, vector<int>, greater<int> > pq;
struct Node {
  int x, y;
};
struct cmp {
  bool operator()(Node a, Node b) {
    if (a.x == b.x) return a.y > b.y;
    return a.x > b.x;
  }
};
bool cmp(int a, int b) { return a > b; }
int a[10010], t[10010];
int main() {
  int n, k;
  while (cin >> n >> k) {
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      cin >> t[i];
    }
    int ans1 = 0, ans2 = 0;
    int tmp = 0;
    for (int i = 1; i <= n; i++) {
      tmp += t[i];
      ans1 += max(0, a[i] - k * tmp);
    }
    tmp = 0;
    for (int i = n; i >= 1; i--) {
      tmp += t[i];
      ans2 += max(0, a[i] - k * tmp);
    }
    if (ans1 == ans2) {
      puts("Tie");
    } else if (ans1 > ans2) {
      puts("Limak");
    } else
      puts("Radewoosh");
  }
  return 0;
}
