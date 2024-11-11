#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int>& p, vector<int>& h, int s) {
  if (h[s] != -1) return;
  if (p[s] == -1)
    h[s] = 1;
  else {
    dfs(p, h, p[s]);
    h[s] = h[p[s]] + 1;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cout << setprecision(12);
  int n;
  cin >> n;
  ;
  vector<int> p(n);
  for (int i = 0; i < n; i++) cin >> p[i];
  ;
  for (int i = 0; i < n; i++) {
    if (p[i] != -1) p[i]--;
  }
  vector<int> h(n, -1);
  for (int i = 0; i < n; i++) {
    dfs(p, h, i);
  }
  int result = 1;
  for (int i = 0; i < n; i++) {
    result = max(result, h[i]);
  }
  cout << result << endl;
}
