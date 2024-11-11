#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 1;
const int N = 1123;
int z, n;
int tab[N];
unordered_set<int> cnt[N];
int sqs[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> tab[i];
  }
  vector<int> tocheck;
  for (int second : cnt[0]) tocheck.push_back(second);
  for (int i = 1; i < 35000; i++) tocheck.push_back(i);
  for (int i = 0; i < n; i++) sqs[i] = sqrt(tab[i]);
  for (int c = 1; c <= tab[0]; c++) {
    int second = tab[0] / c;
    int r = tab[0] - second * c;
    if (second <= sqs[0]) break;
    tocheck.push_back(second);
    if (r == 0 && second - 1) {
      tocheck.push_back(second - 1);
    }
  }
  int best = 0;
  for (int second : tocheck) {
    int ok = 0;
    for (int j = 0; j < n; j++) {
      int first = tab[j] / second - 1;
      assert(tab[j] % second == 0 || tab[j] - second * first - second);
      if (tab[j] % second == 0 || tab[j] - second * first - second - 1 <= first)
        ok++;
      else
        break;
    }
    if (ok == n) {
      best = max(best, second);
    }
  }
  if (0) cout << best << endl;
  best++;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += (tab[i] + best - 1) / best;
  }
  cout << ans << endl;
}
