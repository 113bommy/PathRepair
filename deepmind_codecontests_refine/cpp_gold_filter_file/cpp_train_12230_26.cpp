#include <bits/stdc++.h>
using namespace std;
ifstream fin("test.in");
vector<int> sol;
int maxv2[1000100], maxv1[1000100], minv1[1000100], minv2[1000100];
int last, n, c, a, b;
string s;
void construct(int l, int need) {
  if (l > need) return;
  construct(l + 1, maxv1[l]);
  if (last >= minv2[l]) {
    cout << "IMPOSSIBLE";
    exit(0);
  }
  sol.push_back(l);
  last = max(last, l);
  construct(last + 1, max(need, maxv2[l]));
}
int main() {
  cin >> n >> c;
  for (int i = 1; i <= n; ++i) {
    minv1[i] = n + 1;
    maxv1[i] = i;
    minv2[i] = n + 1;
    maxv2[i] = i;
  }
  for (int i = 1; i <= c; ++i) {
    cin >> a >> b >> s;
    if (b <= a) {
      cout << "IMPOSSIBLE";
      return 0;
    }
    if (s == "LEFT") {
      maxv1[a] = max(maxv1[a], b);
      minv1[a] = min(minv1[a], b);
    } else {
      maxv2[a] = max(maxv2[a], b);
      minv2[a] = min(minv2[a], b);
    }
  }
  construct(1, n);
  for (int i = 0; i < sol.size(); ++i) cout << sol[i] << " ";
}
