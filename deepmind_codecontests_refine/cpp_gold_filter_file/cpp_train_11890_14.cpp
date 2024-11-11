#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e2 + 14;
bool asked[maxn][maxn], les[maxn][maxn];
bool cmp(int v, int u) {
  if (asked[v][u]) return les[v][u];
  asked[v][u] = 1;
  cout << "? " << v + 1 << ' ' << u + 1 << endl;
  char res;
  cin >> res;
  les[v][u] = res == '<';
  return les[v][u];
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    memset(asked, 0, sizeof asked);
    int n;
    cin >> n;
    set<int, bool (*)(int, int)> a(cmp), b(cmp);
    for (int i = 0; i < 2 * n; i++) {
      if (a.size() < b.size())
        a.insert(i);
      else
        b.insert(i);
      if (i >= n)
        if (cmp(*a.begin(), *b.begin()))
          a.erase(a.begin());
        else
          b.erase(b.begin());
    }
    cout << '!' << endl;
  }
}
