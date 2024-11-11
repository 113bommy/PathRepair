#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, L, cost = 0;
  cin >> n >> L;
  vector<pair<long long, long long> > bot(n);
  for (int i = 0; i < n; i++) {
    cin >> bot[i].first;
    bot[i].second = (1LL << i);
  }
  for (int i = 1; i < n; i++) {
    if (bot[i].first >= bot[i - 1].first * 2) {
      bot[i].first = bot[i - 1].first * 2;
    }
  }
  long long tl = L;
  while (L > 0) {
    long long p, c;
    p = L;
    c = LONG_MAX;
    for (int i = n - 1; i >= 0; i--) {
      if (bot[i].second >= L) {
        if (bot[i].first < c) {
          p = bot[i].second;
          c = bot[i].first;
        }
      } else {
        long long req = ceil((L + 0.0) / bot[i].second);
        long long xcost = bot[i].first * req;
        if (xcost < c) {
          c = xcost;
          p = (req * bot[i].second);
        }
      }
    }
    cost += c;
    L -= p;
  }
  L = tl;
  long long last = 0, first = 0;
  for (int i = 0; i < 32; i++)
    if (L & (1LL << i)) last = i;
  for (int i = 0; i < 32; i++)
    if (L & (1LL << i)) {
      first = i;
      break;
    }
  long long maxL = (1LL << (last + 1));
  if (1) {
    while (L < maxL) {
      long long c = 0;
      for (int i = 0; i < 30; i++) {
        if (L & (1LL << i)) {
          if (i < n)
            c = (c + bot[i].first);
          else {
            long long z = ceil(((1LL << i) + 0.0) / bot.back().second);
            c = c + (z * bot.back().first);
          }
        }
      }
      cost = min(cost, c);
      L = L + (L & (-L));
    }
  }
  cout << cost;
}
