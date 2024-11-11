#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
ll mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string str;
  cin >> str;
  int count = 0;
  int n = int(str.size());
  vector<int> freq(26);
  int best = 0;
  int best_idx = -1;
  vector<int> p;
  for (int i = 0; i < str.size(); i++) {
    freq[str[i] - 'a']++;
    int j = i + 1;
    if (j > 1) {
      int f = 0;
      for (int k = 2; k * k <= j; k++) {
        if (j % k == 0) {
          f = 1;
          break;
        }
      }
      if (f == 0) {
        if (2 * j <= n) {
          p.push_back(j);
        }
      } else {
        p.push_back(j);
      }
    }
  }
  for (int i = 0; i < 26; i++) {
    if (freq[i] >= p.size()) {
      best_idx = i;
    }
  }
  if (best_idx == -1)
    cout << "NO";
  else {
    cout << "YES\n";
    char ans[1001] = "a";
    for (int i = 0; i < n; i++) ans[i] = '\0';
    for (int i = 0; i < p.size(); i++) {
      if (p[i] - 1 <= n - 1) {
        ans[p[i] - 1] = 'a' + best_idx;
        freq[best_idx]--;
      }
    }
    int j = 0;
    for (int i = 0; i < n; i++) {
      if (ans[i] == '\0') {
        while (freq[j] == 0) j++;
        ans[i] = 'a' + j;
        freq[j]--;
      }
    }
    cout << ans;
  }
}
