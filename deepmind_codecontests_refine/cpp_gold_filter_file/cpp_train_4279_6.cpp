#include <bits/stdc++.h>
using namespace std;
int max(int a, int b) { return (a > b) ? a : b; }
int min(int a, int b) { return (a < b) ? a : b; }
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  string s, t;
  cin >> s;
  cin >> t;
  unordered_map<char, int> umap;
  vector<int> skips;
  for (int i = 0; i < t.size(); i++) {
    if (umap.find(t[i]) == umap.end()) {
      umap[t[i]] = i;
      skips.push_back(i + 1);
    } else {
      skips.push_back(i - umap[t[i]]);
      umap[t[i]] = i;
    }
  }
  vector<int> counter(n);
  int count = 0, x = 0;
  for (int j = 0; j < n && m + j - 1 < n;) {
    bool ans = 0;
    for (int x = 0; x < m && m + j - 1 < n; x++) {
      if (t[x] != s[j + x]) {
        ans = 0;
        if (x != 0)
          j += skips[x - 1];
        else
          j += 1;
        break;
      } else {
        ans = 1;
      }
    }
    if (ans == 1) {
      count++;
      counter[j + m - 1] = count;
      j += skips[m - 1];
    }
  }
  for (int i = 1; i < n; i++) {
    if (counter[i - 1] != 0 && counter[i] == 0) counter[i] = counter[i - 1];
  }
  for (int i = 0; i < k; i++) {
    int l, r;
    cin >> l >> r;
    if (l - 1 + m - 2 >= 0)
      cout << counter[r - 1] - counter[min(r - 1, l - 1 + m - 2)] << endl;
    else
      cout << counter[r - 1] << endl;
  }
  return 0;
}
