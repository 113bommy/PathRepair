#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 10;
int n;
set<pair<pair<int, int>, int> > a;
int ans[MAXN];
inline pair<pair<int, int>, int> mpi(int a, int b, int c) {
  return make_pair(make_pair(a, b), c);
}
void exit() {
  cout << "Impossible";
  exit(0);
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    pair<pair<int, int>, int> x;
    scanf("%d", &x.first.second);
    x.first.first = x.first.second % 3;
    x.second = i;
    a.insert(x);
  }
  a.insert(mpi(1000, 1000, 1000));
  a.insert(mpi(-1000, -1000, -1000));
  pair<pair<int, int>, int> x;
  int olimp = 0;
  for (int i = 0; i < n; i++) {
    set<pair<pair<int, int>, int> >::iterator it =
        a.lower_bound(mpi(i % 3, i - olimp, 0));
    x = *it;
    if (i % 3 != x.first.first) {
      it--;
      x = *it;
    }
    if (i % 3 != x.first.first) exit();
    bool flag = false;
    while (i - olimp + 1 < x.first.second) {
      it--;
      x = *it;
      flag = true;
    }
    if (x.first.second < 0 || i % 3 != x.first.first) exit();
    olimp = i + 1 - x.first.second;
    ans[i + 1] = x.second;
    a.erase(it);
  }
  cout << "Possible" << endl;
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
}
