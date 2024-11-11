#include <bits/stdc++.h>
using namespace std;
char A[200005] = {};
int vis[200005] = {};
int main() {
  int a;
  while (cin >> a) {
    cin >> A;
    int n = strlen(A);
    char maxr = 0;
    for (int i = 0; i < n - a; i++) {
      char now = A[i];
      int nex = i;
      for (int j = i; j < a + i; j++) {
        if (A[j] < now) {
          nex = j;
          now = A[j];
        }
      }
      maxr = max(maxr, now);
      i = nex;
      vis[i] = 1;
    }
    vector<char> ans;
    for (int i = 0; A[i]; i++) {
      if (vis[i]) ans.push_back(A[i]);
    }
    for (int i = 0; A[i]; i++) {
      if (!vis[i] && A[i] < maxr) {
        ans.push_back(A[i]);
      }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i];
    }
    cout << '\n';
  }
  return 0;
}
