#include <bits/stdc++.h>
using namespace std;
vector<int> G, V, ans[100000 + 10];
int main() {
  int n, k, p, e = 0, o = 0;
  cin >> n >> k >> p;
  for (int i = 0; i < n; i++) {
    int kk;
    cin >> kk;
    if (kk & 1) {
      o++;
      V.push_back(kk);
    } else {
      e++;
      G.push_back(kk);
    }
  }
  int even = p, odd = k - p;
  if (o < odd || (o - odd) & 1 || (even <= o + (o - odd) / 2))
    cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    int indx = 0, vi = 0;
    for (int i = 0; i < odd; i++) {
      ans[indx].push_back(V[i]);
      indx++;
      vi++;
    }
    for (int i = odd; i < V.size() && even > 0; i += 2) {
      ans[indx].push_back(V[i]);
      ans[indx].push_back(V[i + 1]);
      indx++;
      even--;
      vi += 2;
    }
    if (even == 0) indx--;
    for (int i = vi; i < V.size(); i++) ans[indx].push_back(V[i]);
    int id = 0;
    for (int i = 0; i < even - 1; i++) {
      ans[indx].push_back(G[i]);
      indx++;
      id++;
    }
    for (int i = id; i < G.size(); i++) ans[indx].push_back(G[i]);
    indx++;
    for (int i = 0; i < indx; i++) {
      cout << ans[i].size();
      for (int j = 0; j < ans[i].size(); j++) cout << " " << ans[i][j];
      cout << endl;
    }
  }
  return 0;
}
