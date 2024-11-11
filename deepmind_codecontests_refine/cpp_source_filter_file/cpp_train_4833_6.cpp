#include <bits/stdc++.h>
using namespace std;
int n, s, m;
vector<pair<int, int>> bagovi;
vector<pair<int, pair<int, int>>> studenti;
vector<int> moze;
bool proveri_vreme_etc(int vreme) {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      mogu_resiti;
  int treba_pass = 0;
  int j = n - 1;
  int i = m - 1;
  while (j >= 0) {
    int najt = bagovi[i].first;
    for (; j >= 0 && najt <= studenti[j].first; --j)
      mogu_resiti.push(
          make_pair(studenti[j].second.first, studenti[j].second.second));
    if (mogu_resiti.empty()) return false;
    moze[bagovi[i].second] = mogu_resiti.top().second;
    for (int k = 0; k < vreme && (i - k) >= 0; ++k)
      moze[bagovi[i - k].second] = mogu_resiti.top().second;
    i -= vreme;
    treba_pass += mogu_resiti.top().first;
    mogu_resiti.pop();
    if (treba_pass > s) return false;
  }
  return true;
}
int main() {
  scanf("%d%d%d", &n, &m, &s);
  moze.resize(m);
  studenti.resize(n);
  bagovi.resize(m);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &bagovi[i].first);
    bagovi[i].second = i;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &studenti[i].first);
    studenti[i].second.second = i;
  }
  for (int i = 0; i < n; ++i) scanf("%d", &studenti[i].second.first);
  sort(begin(studenti), end(studenti));
  sort(begin(bagovi), end(bagovi));
  int l = 1;
  int r = m;
  while (l < r) {
    int mid = (l + r) / 2;
    if (proveri_vreme_etc(mid))
      r = mid;
    else
      l = mid + 1;
  }
  if (proveri_vreme_etc(min(l, r))) {
    printf("YES\n");
    for (int i = 0; i < m; ++i) printf("%d ", moze[i] + 1);
    return 0;
  }
  printf("NO\n");
  return 0;
}
