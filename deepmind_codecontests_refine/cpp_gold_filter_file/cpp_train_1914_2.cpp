#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e6;
constexpr int size = 1000;
int n, x, y;
map<int, int> mAll, losers, score;
set<int> s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  int siz = (n * (n - 1)) / 2 - 1;
  for (int i = 0; i < siz; i++) {
    cin >> x >> y;
    mAll[y]++;
    mAll[x]++;
    losers[y]++;
  }
  vector<int> missing;
  for (auto i : mAll)
    if (i.second < n - 1) missing.push_back(i.first);
  for (auto i : losers) score[i.second]++;
  if (score[losers[missing[0]]] > 1)
    cout << missing[1] << " " << missing[0] << endl;
  else
    cout << missing[0] << " " << missing[1] << endl;
  return 0;
}
