#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const long long inf = (long long)1e18;
const int infint = (int)2e9;
const int MAXN = 1e6 + 7;
long long h, q;
long long f(long long L, long long ancestor) {
  long long ans = L;
  ans *= 1LL << (h - ancestor);
  return ans;
}
long long g(long long R, long long ancestor) {
  long long ans = R + 1;
  ans *= 1LL << (h - ancestor);
  return --ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> h >> q;
  long long probl = 1LL << (h - 1), probr = (1LL << h) - 1;
  vector<pair<long long, long long> > P;
  for (int i = 0; i < q; i++) {
    long long h1, L, R, ans;
    cin >> h1 >> L >> R >> ans;
    L = f(L, h1);
    R = g(R, h1);
    if (ans == 1) {
      probl = max(probl, L);
      probr = min(probr, R);
    } else {
      P.push_back(make_pair(L, R));
    }
  }
  if (probr < probl) return cout << "Game cheated!", 0;
  sort(P.begin(), P.end());
  vector<pair<long long, long long> > NOS;
  int ptr1 = 0;
  while (ptr1 < P.size()) {
    long long last = P[ptr1].second, ptr2 = ptr1 + 1;
    while (ptr2 < P.size() and P[ptr2].first <= last) {
      last = max(last, (long long)P[ptr2].second);
      ptr2++;
    }
    NOS.push_back(make_pair(P[ptr1].first, last));
    ptr1 = ptr2;
  }
  long long len = probr - probl + 1;
  vector<pair<long long, long long> > V;
  for (int i = 0; i < NOS.size(); i++) {
    long long u = max(probl, NOS[i].first), v = min(probr, NOS[i].second),
              tmp = v - u + 1;
    if (tmp > 0) {
      len -= tmp;
      V.push_back(make_pair(u, v));
    }
  }
  if (len == 0) return cout << "Game cheated!", 0;
  if (len > 1) return cout << "Data not sufficient!", 0;
  if (V.size() == 0) return cout << probl, 0;
  if (V.back().second < probr) return cout << probr, 0;
  if (V[0].first > probl) return cout << probl, 0;
  for (int i = 1; i < V.size(); i++)
    if (V[i - 1].second + 1 != V[i].first) cout << V[i - 1].second + 1 << " ";
}
