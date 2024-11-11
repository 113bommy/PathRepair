#include <bits/stdc++.h>
using namespace std;
const int mx = 2e6 + 6;
unordered_map<int, int> m;
map<int, int> msif;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  int lans = 1, rans = 1;
  int l = 1;
  long long sif = 0;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    a[i] = x;
    m[x]++;
    if (msif[a[l]] == 1) {
      msif[a[l]] = 0;
      sif--;
    }
    while (m.size() - sif > k) {
      m[a[l]]--;
      if (m[a[l]] == 0) {
        msif[a[l]] = 1;
        sif++;
      }
      ++l;
    }
    if (i - l + 1 > rans - lans + 1) {
      lans = l;
      rans = i;
    }
  }
  cout << lans << " " << rans << '\n';
}
