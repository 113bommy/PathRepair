#include <bits/stdc++.h>
using namespace std;
vector<long long> ans;
long long a, b;
long long bfs(long long x) {
  if (x <= a) {
    ans.push_back(x);
    return x;
  }
  if (x % 2 == 0) {
    ans.push_back(x / 2);
    return bfs(x /= 2);
  } else if (x % 10 == 1) {
    x /= 10;
    ans.push_back(x);
    return bfs(x);
  }
  return x;
}
int main() {
  cin >> a >> b;
  long long x = bfs(b);
  if (x == a) {
    cout << "YES\n";
    cout << ans.size() << "\n";
    for (int i = ans.size() - 2; i > 0; i--) {
      cout << ans[i] << " ";
    }
    cout << b;
  } else
    cout << "NO";
  return 0;
}
