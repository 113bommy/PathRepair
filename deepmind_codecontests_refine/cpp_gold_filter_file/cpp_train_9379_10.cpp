#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
pair<int, int> a[N], b[N];
multiset<int> mx[2], mn[2];
void add(int i) {
  mx[0].insert(a[i].first);
  mx[1].insert(a[i].second);
  mn[0].insert(b[i].first);
  mn[1].insert(b[i].second);
}
void del(int i) {
  mx[0].erase(mx[0].find(a[i].first));
  mx[1].erase(mx[1].find(a[i].second));
  mn[0].erase(mn[0].find(b[i].first));
  mn[1].erase(mn[1].find(b[i].second));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i].first >> a[i].second >> b[i].first >> b[i].second, add(i);
  for (int i = 0; i < n; ++i) {
    del(i);
    int lx = *mx[0].rbegin();
    int rx = *mn[0].begin();
    int ly = *mx[1].rbegin();
    int ry = *mn[1].begin();
    if (lx <= rx && ly <= ry) {
      cout << lx << ' ' << ly;
      return 0;
    }
    add(i);
  }
  return 0;
}
