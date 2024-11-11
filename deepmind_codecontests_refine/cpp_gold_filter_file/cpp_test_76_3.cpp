#include <bits/stdc++.h>
const int N = 2e5 + 5;
using namespace std;
long long n, m, ok1, ok2;
vector<int> g[N];
set<int> choose;
set<int>::iterator iter1, iter2;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = (1); i <= (m); i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y), g[y].push_back(x);
  }
  for (int i = (1); i <= (n); i++) sort(g[i].begin(), g[i].end());
  for (int cas = 1; cas <= 500000; cas++) {
    ok1 = ok2 = 1;
    choose.clear();
    for (int i = (1); i <= (5); i++) {
      int tmp = (rand() % n) + 1;
      while (i > 1 && choose.count(tmp)) tmp = rand() % n + 1;
      choose.insert(tmp);
    }
    for (iter1 = choose.begin(); iter1 != choose.end(); iter1++) {
      for (iter2 = choose.begin(); iter2 != choose.end(); iter2++) {
        if (*iter2 == *iter1) continue;
        if (ok1 && binary_search(g[*iter1].begin(), g[*iter1].end(), *iter2)) {
          ok1 = 0;
          break;
        }
        if (ok2 && !binary_search(g[*iter1].begin(), g[*iter1].end(), *iter2)) {
          ok2 = 0;
          break;
        }
      }
      if (!ok1 && !ok2) break;
    }
    if (ok1 || ok2) {
      for (iter1 = choose.begin(); iter1 != choose.end(); iter1++)
        cout << *iter1 << " ";
      cout << endl;
      return 0;
    }
  }
  puts("-1");
}
