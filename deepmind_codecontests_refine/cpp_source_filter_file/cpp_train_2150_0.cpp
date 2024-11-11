#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000001;
const long double EPS = 1e-9;
const int MOD = 1000000007;
const long long LLINF = 1000000000000000001;
const int treeh = (1 << 18);
const int maxn = 200004;
int n;
int c1[maxn];
int c2[maxn];
int l1[maxn];
int l2[maxn];
int t[2][2 * maxn];
pair<int, int> p[maxn];
vector<pair<int, int> > truep;
vector<pair<int, pair<int, int> > > eve;
void sett(int v, int p, int* t) {
  p += treeh;
  t[p] += v;
  while (p > 1) {
    p /= 2;
    t[p] = t[p * 2] + t[p * 2 + 1];
  }
}
int readt(int a, int b, int* t) {
  a += treeh;
  b += treeh;
  if (a == b) return t[a];
  int r = t[a] + t[b];
  while (a / 2 != b / 2) {
    if (a % 2 == 0) r += t[a + 1];
    if (b % 2 == 1) r += t[b - 1];
    a /= 2;
    b /= 2;
  }
  return r;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> p[i].first >> p[i].second;
    p[i].first += 100001;
    p[i].second += 100001;
  }
  for (int modd = 0; modd <= 1; modd++) {
    truep.clear();
    for (int i = 1; i <= n; i++) {
      if ((p[i].first + p[i].second) % 2 == modd) truep.push_back(p[i]);
    }
    for (int i = 0; i <= maxn - 1; i++) {
      c1[i] = INF;
      c2[i] = -INF;
    }
    for (auto i : truep) {
      c1[i.first] = min(c1[i.first], i.second + 1);
      c2[i.first] = max(c2[i.first], i.second - 1);
    }
    for (int i = 1; i <= maxn - 2; i++) {
      c1[i] = min(c1[i - 1] + 1, c1[i]);
      c2[i] = max(c2[i - 1] - 1, c2[i]);
    }
    for (int i = maxn - 2; i >= 1; i--) {
      c1[i] = min(c1[i + 1] + 1, c1[i]);
      c2[i] = max(c2[i + 1] - 1, c2[i]);
    }
    for (int i = 0; i <= maxn - 1; i++) {
      l1[i] = INF;
      l2[i] = -INF;
    }
    for (auto i : truep) {
      l1[i.second] = min(l1[i.second], i.first + 1);
      l2[i.second] = max(l2[i.second], i.first - 1);
    }
    for (int i = 1; i <= maxn - 2; i++) {
      l1[i] = min(l1[i - 1] + 1, l1[i]);
      l2[i] = max(l2[i - 1] - 1, l2[i]);
    }
    for (int i = maxn - 2; i >= 1; i--) {
      l1[i] = min(l1[i + 1] + 1, l1[i]);
      l2[i] = max(l2[i + 1] - 1, l2[i]);
    }
    eve.clear();
    for (int i = 1; i <= maxn - 1; i++) {
      if (l1[i] <= l2[i]) {
        eve.push_back(make_pair(l1[i], make_pair(i, 1)));
        eve.push_back(make_pair(l2[i] + 1, make_pair(i, -1)));
      }
    }
    sort((eve).begin(), (eve).end());
    int j = 0;
    for (int i = 1; i <= maxn - 1; i++) {
      while (j < ((int)(eve).size()) && eve[j].first == i) {
        sett(eve[j].second.second, eve[j].second.first,
             t[(eve[j].second.first % 2)]);
        j++;
      }
      if (c1[i] <= c2[i]) {
        ans += readt(c1[i], c2[i], t[((i + 1) % 2) ^ modd]);
      }
    }
  }
  cout << ans << endl;
}
