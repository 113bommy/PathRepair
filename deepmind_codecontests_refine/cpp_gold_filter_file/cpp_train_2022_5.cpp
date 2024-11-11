#include <bits/stdc++.h>
using namespace std;
const int MAXN = (1 << 24), MAX = 24;
int A[MAXN], F[MAXN];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    vector<int> v;
    for (auto c : s) {
      v.push_back(c - 'a');
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int m = 1; m < (1 << ((int)v.size())); ++m) {
      int submask = 0;
      for (int j = 0; j < ((int)v.size()); ++j) {
        if ((1 << j) & m) {
          submask ^= (1 << v[j]);
        }
      }
      if (__builtin_popcount(m) % 2) {
        A[submask]++;
      } else {
        A[submask]--;
      }
    }
  }
  for (int i = 0; i < (1 << MAX); ++i) {
    F[i] = A[i];
  }
  for (int i = 0; i < MAX; ++i)
    for (int mask = 0; mask < (1 << MAX); ++mask) {
      if (mask & (1 << i)) {
        F[mask] += F[mask ^ (1 << i)];
      }
    }
  int sol = 0;
  for (int i = 0; i < (1 << MAX); ++i) {
    sol ^= F[i] * F[i];
  }
  cout << sol << endl;
}
