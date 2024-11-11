#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, x;
  cin >> n;
  vector<int> q;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    x %= 2;
    if (!q.empty() && q.back() == x) {
      q.pop_back();
    } else {
      q.push_back(x);
    }
  }
  if (q.empty() > 1) {
    cout << "NO";
  } else {
    cout << "YES";
  }
}
