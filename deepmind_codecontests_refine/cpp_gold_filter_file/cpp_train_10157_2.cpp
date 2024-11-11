#include <bits/stdc++.h>
const long long mod = 1000000007;
int Inf = (int)2e9;
using namespace std;
bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  if (a.first.first > b.first.first) return false;
  if (a.first.first < b.first.first) return true;
  if (a.second > b.second) return true;
  return false;
}
int main() {
  int n;
  scanf("%d", &(n));
  vector<pair<pair<int, int>, int>> plac(n);
  int cplus = 0, cmin = 0;
  for (int(i) = 0; (i) < n; (i)++) {
    scanf("%d", &(plac[i].first.first));
    scanf("%d", &(plac[i].first.second));
    if (plac[i].first.second > 0)
      cplus++;
    else if (plac[i].first.second < 0)
      cmin++;
    plac[i].second = i;
  }
  int ans = 0;
  plac.push_back(make_pair(make_pair(-1000, 0), 100000));
  plac.push_back(make_pair(make_pair(1000, 0), -100000));
  sort(plac.rbegin(), plac.rend(), comp);
  for (int i = 0; i < cplus; i++) {
    for (int j = n; j >= 1; j--) {
      if (plac[j].first.second > 0) {
        plac[j].first.first += plac[j].first.second;
        plac[j].first.second = 0;
        int idx = j;
        while (plac[idx - 1].first.first < plac[idx].first.first) {
          swap(plac[idx], plac[idx - 1]);
          idx--;
          ans++;
        }
        while (plac[idx - 1].first.first == plac[idx].first.first &&
               plac[idx - 1].second > plac[idx].second) {
          swap(plac[idx], plac[idx - 1]);
          idx--;
          ans++;
        }
        break;
      }
    }
  }
  for (int i = 0; i < cmin; i++) {
    for (int j = 1; j <= n; j++) {
      if (plac[j].first.second < 0) {
        int idx = j;
        plac[j].first.first += plac[j].first.second;
        plac[j].first.second = 0;
        while (plac[idx + 1].first.first > plac[idx].first.first) {
          swap(plac[idx], plac[idx + 1]);
          idx++;
          ans++;
        }
        while (plac[idx + 1].first.first == plac[idx].first.first &&
               plac[idx + 1].second < plac[idx].second) {
          swap(plac[idx], plac[idx + 1]);
          idx++;
          ans++;
        }
        break;
      }
    }
  }
  cout << ans;
  return 0;
}
