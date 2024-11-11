#include <bits/stdc++.h>
using namespace std;
const int N = 3e6 + 2;
int a[N];
int rChild[N], lChild[N], fat[N], prof[N];
int h, g;
bool doit(int u) {
  if (a[lChild[u]] == 0 && a[rChild[u]] == 0) {
    if (prof[u] <= g) return false;
    return true;
  }
  if (a[lChild[u]] > a[rChild[u]])
    return doit(lChild[u]);
  else
    return doit(rChild[u]);
}
void changeIt(int u) {
  if (a[lChild[u]] == 0 && a[rChild[u]] == 0) {
    a[u] = 0;
    return;
  }
  if (a[lChild[u]] > a[rChild[u]])
    a[u] = a[lChild[u]], changeIt(lChild[u]);
  else
    a[u] = a[rChild[u]], changeIt(rChild[u]);
}
vector<int> ans;
long long go(int root) {
  long long cur = 0;
  while (1) {
    if (doit(root))
      cur += a[root], ans.push_back(root), changeIt(root);
    else {
      int u = root;
      while (1) {
        if (a[lChild[u]] == 0 && a[rChild[u]] == 0) break;
        if (a[lChild[u]] > a[rChild[u]])
          cur += go(rChild[u]), u = lChild[u];
        else
          cur += go(lChild[u]), u = rChild[u];
      }
      break;
    }
  }
  return cur;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> h >> g;
    int cnt = 0, curP = 0;
    long long s = 0;
    for (int i = 1; i < (1 << h); ++i) {
      cin >> a[i];
      s += a[i];
      lChild[i] = 2 * i;
      rChild[i] = 2 * i + 1;
      fat[i] = i / 2;
      prof[i] = curP + 1;
      cnt++;
      if (cnt >= (1 << curP)) {
        curP++;
        cnt = 0;
      }
    }
    cout << s - go(1) << '\n';
    for (auto i : ans) cout << i << ' ';
    cout << '\n';
    ans.clear();
    for (int i = 1; i < (1 << h); ++i) a[i] = 0;
  }
}
