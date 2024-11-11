#include <bits/stdc++.h>
using namespace std;
struct rating {
  int x, id;
};
bool cmp(rating a, rating b) { return a.x < b.x; }
int main() {
  int n, b[2001];
  rating a[2001];
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].x;
    a[i].id = i;
  }
  sort(a + 1, a + n + 1, cmp);
  int ranking = 0;
  a[n + 1].x = a[n].x + 1;
  int dem = 1;
  for (int i = n; i >= 1; --i) {
    if (a[i].x < a[i + 1].x) {
      ranking += dem;
      dem = 1;
    }
    if (a[i].x == a[i + 1].x) ++dem;
    b[a[i].id] = ranking;
  }
  for (int i = 1; i <= n; ++i) cout << b[i] << " ";
}
