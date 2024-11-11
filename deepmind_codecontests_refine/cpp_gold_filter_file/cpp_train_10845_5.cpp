#include <bits/stdc++.h>
using namespace std;
const int N = 111;
struct node {
  int a, b;
  bool operator<(const node o) const {
    if (b >= 0 && o.b < 0) return true;
    if (b < 0 && o.b >= 0) return false;
    if (b >= 0 && o.b >= 0) return a < o.a;
    return a + b > o.a + o.b;
  }
} pro[N];
int n, k;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) scanf("%d%d", &pro[i].a, &pro[i].b);
  sort(pro + 1, pro + 1 + n);
  for (int i = 1; i <= n; i++) {
    if (k + pro[i].b < 0 || k < pro[i].a) {
      cout << "NO" << endl;
      return 0;
    }
    k += pro[i].b;
  }
  cout << (k >= 0 ? "YES" : "NO") << endl;
  return 0;
}
