#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)1e5 + 10;
int n, m, f[MAXN], l[MAXN], r[MAXN], opp[MAXN], t, T, N, bel[MAXN], vis[MAXN];
vector<pair<int, pair<int, int> > > L;
int getf(int first) {
  if (f[first] == first) return first;
  f[first] = getf(f[first]);
  return f[first];
}
void fail() { puts("IMPOSSIBLE"), exit(0); }
void check(int first, int second) {
  if (!(first + second >= t && first + second <= T)) return;
  ++first, ++second;
  memset(bel, 0, sizeof(bel));
  for (int i = 1; i <= n; ++i)
    if (getf(i) == i && !bel[opp[i]]) {
      if (!opp[i]) {
        if (l[i] <= first && first <= r[i]) bel[i] = 1;
        if (l[i] <= second && second <= r[i]) bel[i] = 2;
      } else {
        if (l[i] <= first && first <= r[i] && l[opp[i]] <= second &&
            second <= r[opp[i]])
          bel[i] = 1, bel[opp[i]] = 2;
        if (l[i] <= second && second <= r[i] && l[opp[i]] <= first &&
            first <= r[opp[i]])
          bel[i] = 2, bel[opp[i]] = 1;
      }
      if (!bel[i]) return;
    }
  puts("POSSIBLE");
  printf("%d %d\n", first - 1, second - 1);
  for (int i = 1; i <= n; ++i) printf("%d", bel[getf(i)]);
  puts(""), exit(0);
}
void check(int p, int l, int r) {
  if (l <= t - p && t - p <= r) check(p, t - p);
  if (l <= T - p && T - p <= r) check(p, T - p);
  check(p, l), check(p, r);
}
void check(int al, int ar, int bl, int br) {
  --al, --ar, --bl, --br;
  check(al, bl, br), check(ar, bl, br), check(bl, al, ar), check(br, al, ar);
}
int main() {
  scanf("%d%d%d%d", &t, &T, &n, &m);
  for (int i = 1; i <= n; ++i)
    scanf("%d%d", &l[i], &r[i]), f[i] = i, ++l[i], ++r[i];
  for (int i = 1; i <= m; ++i) {
    int first, second;
    scanf("%d%d", &first, &second);
    first = getf(first), second = getf(second);
    if (first == second) fail();
    if (!opp[first] && !opp[second])
      opp[first] = second, opp[second] = first;
    else if (!opp[first] || !opp[second]) {
      if (!opp[first]) swap(first, second);
      f[second] = opp[first];
    } else {
      f[opp[first]] = second, f[opp[second]] = first;
      opp[first] = second, opp[second] = first;
    }
  }
  for (int i = 1; i <= n; ++i) {
    int first = getf(i);
    l[first] = max(l[first], l[i]);
    r[first] = min(r[first], r[i]);
    if (l[first] > r[first]) fail();
    if (i == first) N += 1 + !opp[i];
  }
  for (int i = 1; i <= n; ++i)
    if (getf(i) == i && !vis[i]) {
      if (!opp[i]) {
        L.push_back(make_pair(1, make_pair(l[i], 0)));
        L.push_back(make_pair(1, make_pair(r[i], 1)));
        L.push_back(make_pair(l[i], make_pair(-l[i], 0)));
        L.push_back(make_pair(l[i], make_pair(-r[i], 1)));
        L.push_back(make_pair(l[i], make_pair(1, 0)));
        L.push_back(make_pair(l[i], make_pair((int)1e9 + 1, 1)));
        L.push_back(make_pair(r[i] + 1, make_pair(-1, 0)));
        L.push_back(make_pair(r[i] + 1, make_pair(-((int)1e9 + 1), 1)));
        L.push_back(make_pair(r[i] + 1, make_pair(l[i], 0)));
        L.push_back(make_pair(r[i] + 1, make_pair(r[i], 1)));
        L.push_back(make_pair((int)1e9 + 1, make_pair(-l[i], 0)));
        L.push_back(make_pair((int)1e9 + 1, make_pair(-r[i], 1)));
      } else {
        int j = opp[i];
        if (r[i] < l[j] || r[j] < l[i])
          L.push_back(make_pair(l[i], make_pair(l[j], 0))),
              L.push_back(make_pair(l[i], make_pair(r[j], 1))),
              L.push_back(make_pair(r[i] + 1, make_pair(-l[j], 0))),
              L.push_back(make_pair(r[i] + 1, make_pair(-r[j], 1)));
        else if (l[i] <= l[j] && r[j] <= r[i]) {
          vis[i] = vis[j] = 1;
          L.push_back(make_pair(l[i], make_pair(l[j], 0))),
              L.push_back(make_pair(l[i], make_pair(r[j], 1))),
              L.push_back(make_pair(l[j], make_pair(-l[j], 0))),
              L.push_back(make_pair(l[j], make_pair(-r[j], 1))),
              L.push_back(make_pair(l[j], make_pair(l[i], 0))),
              L.push_back(make_pair(l[j], make_pair(r[i], 1))),
              L.push_back(make_pair(r[j] + 1, make_pair(-l[i], 0))),
              L.push_back(make_pair(r[j] + 1, make_pair(-r[i], 1))),
              L.push_back(make_pair(r[j] + 1, make_pair(l[j], 0))),
              L.push_back(make_pair(r[j] + 1, make_pair(r[j], 1))),
              L.push_back(make_pair(r[i] + 1, make_pair(-l[j], 0))),
              L.push_back(make_pair(r[i] + 1, make_pair(-r[j], 1)));
        } else if (l[i] <= l[j] && l[j] <= r[i] && r[i] <= r[j]) {
          vis[i] = vis[j] = 1;
          L.push_back(make_pair(l[i], make_pair(l[j], 0))),
              L.push_back(make_pair(l[i], make_pair(r[j], 1))),
              L.push_back(make_pair(l[j], make_pair(-l[j], 0))),
              L.push_back(make_pair(l[j], make_pair(l[i], 0))),
              L.push_back(make_pair(r[i] + 1, make_pair(-r[j], 1)));
          L.push_back(make_pair(r[i] + 1, make_pair(r[i], 1)));
          L.push_back(make_pair(r[j] + 1, make_pair(-l[i], 0)));
          L.push_back(make_pair(r[j] + 1, make_pair(-r[i], 1)));
        }
      }
    }
  for (int i = 0; i < ((int)(L).size()); ++i)
    L[i].second.first = -L[i].second.first;
  sort((L).begin(), (L).end());
  multiset<int> s[2];
  N /= 2;
  for (int i = 0; i < ((int)(L).size()); ++i) {
    if (L[i].second.first < 0)
      s[L[i].second.second].insert(-L[i].second.first);
    else
      s[L[i].second.second].erase(
          s[L[i].second.second].lower_bound(L[i].second.first));
    if (((int)(s[0]).size()) == N && ((int)(s[1]).size()) == N &&
        *s[0].rbegin() <= *s[1].begin())
      if (i < ((int)(L).size()) - 1 && L[i].first < L[i + 1].first)
        check(L[i].first, L[i + 1].first - 1, *s[0].rbegin(), *s[1].begin());
  }
  fail();
  fclose(stdin);
  fclose(stdout);
  return 0;
}
