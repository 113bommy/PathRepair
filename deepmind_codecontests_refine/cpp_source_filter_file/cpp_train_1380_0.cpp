#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  vector<vector<long long int> > query(13);
  vector<long long int> masks(n);
  long long int assigned = 0;
  for (long long int i = 0LL; i < (1 << 13); i++) {
    if (__builtin_popcount(i) != 13 / 2) continue;
    masks[assigned] = i;
    for (long long int j = 0; j < 13; j++) {
      if ((i >> j & 1)) {
        query[j].push_back(assigned);
      }
    }
    assigned++;
    if (assigned >= n) break;
  }
  vector<long long int> result(13);
  for (long long int i = 0; i < 13; i++) {
    if (query[i].size() == 0)
      continue;
    else {
      cout << "? " << query[i].size() << " ";
      for (auto e : query[i]) cout << e << " ";
    }
    cout << "\n";
    cout.flush();
    cin >> result[i];
  }
  vector<long long int> final_answer(n);
  for (long long int i = 0LL; i < n; i++) {
    for (long long int j = 0LL; j < 13; j++) {
      if ((masks[i] >> j & 1) == 0) {
        final_answer[i] |= result[j];
      }
    }
  }
  cout << "! ";
  for (auto e : final_answer) {
    cout << e << " ";
  }
  cout << "\n";
  cout.flush();
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  for (long long int tt = 1; tt < t + 1; tt++) {
    solve();
  }
}
