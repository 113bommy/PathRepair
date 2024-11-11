#include <bits/stdc++.h>
using namespace std;
bool mycomp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  return a.first.second < b.first.second;
}
int main() {
  int max_health, reg, netdmg = 0, n, per, dmg, health, t = 0;
  scanf("%d %d %d", &n, &max_health, &reg);
  vector<pair<pair<int, int>, int> > A(n);
  for (int i = 0; i < (n); ++i) {
    scanf("%d %d", &per, &dmg);
    A[i] = make_pair(make_pair(per * max_health / 100, dmg), i + 1);
  }
  sort(A.begin(), A.end());
  health = max_health;
  vector<pair<pair<int, int>, int> >::iterator p, best;
  pair<pair<int, int>, int> scroll;
  bool success = true;
  vector<pair<int, int> > result;
  while (1) {
    p = lower_bound(A.begin(), A.end(), make_pair(make_pair(health, 0), 0));
    if (p != A.end()) {
      best = max_element(p, A.end(), mycomp);
      scroll = *best;
      A.erase(best);
      netdmg += scroll.first.second;
      result.push_back(make_pair(t, scroll.second));
    } else {
      if (reg - netdmg >= 0) {
        success = false;
        break;
      }
    }
    health -= (netdmg - reg);
    if (health <= 0) break;
    health = (health) < (max_health) ? (health) : (max_health);
    ++t;
  }
  ++t;
  if (success) {
    printf("YES\n");
    printf("%d %d\n", t, result.size());
    for (int i = 0; i < (result.size()); ++i)
      printf("%d %d\n", result[i].first, result[i].second);
  } else {
    printf("NO\n");
  }
  return 0;
}
