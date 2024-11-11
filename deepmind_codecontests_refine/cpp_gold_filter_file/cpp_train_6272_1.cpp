#include <bits/stdc++.h>
using namespace std;
int interact(vector<int> &ask) {
  cout << "? " << ask.size() << " ";
  for (auto &i : ask) cout << i << " ";
  cout << endl;
  int x;
  cin >> x;
  return x;
}
vector<int> complement(vector<int> s, int n) {
  vector<int> occour(n + 1, 0);
  for (auto &i : s) occour[i] = 1;
  vector<int> ask;
  for (int i = 1; i <= n; i++)
    if (!occour[i]) ask.push_back(i);
  return ask;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> S(k);
    for (int i = 0; i < k; i++) {
      int c;
      cin >> c;
      for (int j = 0; j < c; j++) {
        int in;
        cin >> in;
        S[i].push_back(in);
      }
    }
    vector<int> ask;
    for (int i = 1; i <= n; i++) ask.push_back(i);
    int maximus = interact(ask);
    int l = 0, r = k - 1;
    while (l < r) {
      ask.clear();
      int mid = (l + r) / 2;
      for (int i = 0; i <= mid; i++) {
        for (auto &j : S[i]) ask.push_back(j);
      }
      int x = interact(ask);
      if (x == maximus)
        r = mid;
      else
        l = mid + 1;
    }
    vector<int> ans(k);
    ask = complement(S[l], n);
    for (int i = 0; i < k; i++) {
      if (i == l)
        ans[i] = interact(ask);
      else
        ans[i] = maximus;
    }
    cout << "! ";
    for (auto &i : ans) cout << i << " ";
    cout << endl;
    string correct;
    cin >> correct;
  }
  return 0;
}
