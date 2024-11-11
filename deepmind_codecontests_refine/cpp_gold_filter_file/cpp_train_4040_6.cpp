#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> vs[100001];
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    if (m - a < 0) continue;
    vs[m - a].push_back(b);
  }
  
  priority_queue<int> q;
  long ans = 0;
  for (int j = m; j >= 0; --j) {
    for (int c : vs[j]) {
      q.push(c);
    }
    if (q.empty()) continue;
    ans += q.top();
    q.pop();
  }
  cout << ans << endl;
  
}