#include <bits/stdc++.h>
using namespace std;
vector<int> arr[27];
bool removed[400005];
int main() {
  int n, k;
  string s;
  cin >> n >> k;
  cin >> s;
  for (int i = 0; i < n; i++) arr[s[i] - 'a'].push_back(i);
  for (int i = 0; i <= 26; i++) reverse(arr[i].begin(), arr[i].end());
  while (k--) {
    for (int i = 0; i <= 26; i++) {
      if (arr[i].size() > 0) {
        removed[arr[i][arr[i].size() - 1]] = true;
        arr[i].pop_back();
        break;
      }
    }
  }
  for (int i = 0; i <= n; i++) {
    if (!removed[i]) cout << s[i];
  }
}
