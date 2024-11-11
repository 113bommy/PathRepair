#include <bits/stdc++.h>
using namespace std;
map<int, bool> chat;
queue<int> screem;
vector<int> ans;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, k, id;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> id;
    if (chat[id] == 0) {
      if (screem.size() < k) {
        screem.push(id);
        chat[id] = 1;
      } else {
        if (chat[id] == 0) {
          chat[screem.front()] = 0;
          screem.pop();
          screem.push(id);
          chat[id] = 1;
        }
      }
    }
  }
  n = screem.size();
  cout << n << endl;
  for (int i = 0; i < n; i++) {
    ans.push_back(screem.front());
    screem.pop();
  }
  for (int i = n; i >= 0; i--) {
    cout << ans[i] << " ";
  }
  return 0;
}
