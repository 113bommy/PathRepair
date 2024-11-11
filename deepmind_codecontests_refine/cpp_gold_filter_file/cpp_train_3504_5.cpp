#include <bits/stdc++.h>
using namespace std;
const int N = 64;
vector<long long> g[N];
vector<int> cnt(N, 0);
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i += 1) {
    long long b;
    cin >> b;
    for (int j = 0; j < N; j += 1) {
      if ((1ll << j) > b) {
        g[j - 1].push_back(b);
        break;
      }
    }
  }
  list<long long> ans;
  for (int i = N - 1; i >= 0; i -= 1) {
    if (g[i].size() == 0) continue;
    ans.push_front(g[i][cnt[i]++]);
    auto itr = ans.begin();
    long long val = *itr;
    while (cnt[i] < g[i].size() && itr != ans.end()) {
      if (val & (1ll << i)) {
        itr++;
        if (itr != ans.end()) val ^= *itr;
      } else {
        itr++;
        ans.insert(itr, g[i][cnt[i]++]);
        itr--;
        val ^= *itr;
      }
    }
    if (cnt[i] < g[i].size()) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  for (long long x : ans) cout << x << " ";
  cout << endl;
}
