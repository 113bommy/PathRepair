#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  cin >> a;
  int n = a.size();
  int k;
  cin >> k;
  vector<pair<int, int> > D(26);
  bool used[26];
  for (int i = 0; i < 26; i++) {
    D[i].first = 0;
    D[i].second = i;
    used[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    int x = a[i] - 'a';
    D[x].first++;
  }
  sort(D.begin(), D.end());
  int sum = 0;
  int i = 0;
  while (sum + D[i].first < k && i < 26) {
    sum = sum + D[i].first;
    used[D[i].second] = 1;
    i++;
  }
  vector<char> ans;
  int t = 0;
  map<int, bool> M;
  for (int i = 0; i < n; i++) {
    int y = a[i] - 'a';
    if (used[y] == 0) {
      ans.push_back(a[i]);
      if (M[y] == 0) {
        M[y] = 1;
        t++;
      }
    }
  }
  cout << t << "\n";
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i];
  }
  return 0;
}
