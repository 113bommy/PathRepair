#include <bits/stdc++.h>
using namespace std;
vector<int> rats[2001];
int s[2001];
int ranks[2001];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    rats[s[i]].push_back(i);
  }
  ranks[2000] = 1;
  for (int i = 2000 - 1; i >= 0; --i) {
    ranks[i] = rats[i + 1].size() + ranks[i + 1];
  }
  for (int i = 0; i < n; ++i) {
    cout << ranks[s[i]] << " \n"[i == n - 1];
  }
  return 0;
}
