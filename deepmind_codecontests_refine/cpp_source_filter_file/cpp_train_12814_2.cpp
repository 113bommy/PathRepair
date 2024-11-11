#include <bits/stdc++.h>
using namespace std;
int n;
string s, t;
int main() {
  cin >> n >> s >> t;
  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i]) {
      bool found = false;
      for (int j = i + 1; j < n; j++) {
        if (s[i] == t[j]) {
          for (int k = j - 1; k >= i; k--) {
            q.push(k + 1);
            swap(t[k], t[k + 1]);
          }
          found = true;
          break;
        }
      }
      if (!found) {
        cout << -1;
        return 0;
      }
    }
  }
  cout << q.size() << endl;
  if (!q.empty()) {
    cout << q.front();
    q.pop();
  }
  while (!q.empty()) {
    cout << ' ' << q.front();
    q.pop();
  }
  return 0;
}
