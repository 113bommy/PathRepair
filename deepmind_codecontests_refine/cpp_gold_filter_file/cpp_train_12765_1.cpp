#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > p;
int main() {
  int n, S, sum = 0;
  long long ans = 0;
  scanf("%d%d", &n, &S);
  for (int i = 0; i < n; i++) {
    int s, a, b;
    scanf("%d%d%d", &s, &a, &b);
    sum += s;
    sum %= S;
    ans += (long long)s * a;
    p.push_back(make_pair(b - a, s));
  }
  if (sum) p.push_back(make_pair(0, S - sum));
  sort(p.begin(), p.end());
  reverse(p.begin(), p.end());
  long long cur = 0, part = 0, best = 0;
  for (int i = 0; i < p.size(); i++) {
    if (part + p[i].second >= S) {
      best = max(best, cur + (long long)p[i].first * (S - part));
      best = max(best, cur + (long long)p[i].first *
                                 ((part + p[i].second) / S * S - part));
    }
    cur += (long long)p[i].first * p[i].second;
    part += p[i].second;
    part %= S;
  }
  cout << ans + best;
  return 0;
}
