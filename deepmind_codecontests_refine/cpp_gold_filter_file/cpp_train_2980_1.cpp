#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6;
map<pair<long long, long long>, long long> alice, bob;
map<pair<long long, long long>, long long> iteration;
map<long long, pair<long long, long long>> points;
long long play(long long a, long long b) {
  if (a == 1 && b == 3) return 1;
  if (a == 3 && b == 2) return 1;
  if (a == 2 && b == 1) return 1;
  if (a == b) return 0;
  return -1;
}
signed main() {
  long long k, a, b;
  cin >> k >> a >> b;
  for (long long i = 1; i <= 3; i++) {
    for (long long j = 1; j <= 3; j++) {
      cin >> alice[{i, j}];
    }
  }
  for (long long i = 1; i <= 3; i++) {
    for (long long j = 1; j <= 3; j++) {
      cin >> bob[{i, j}];
    }
  }
  long long c = 1;
  while (!iteration[{a, b}] && k) {
    iteration[{a, b}] = c++;
    points[c - 1] = points[c - 2];
    long long t = play(a, b);
    if (t == -1) points[c - 1].second++;
    if (t == 1) points[c - 1].first++;
    long long a1 = alice[{a, b}];
    long long b1 = bob[{a, b}];
    a = a1, b = b1;
    k--;
  }
  long long sz = c - iteration[{a, b}];
  pair<long long, long long> score = points[c - 1];
  pair<long long, long long> kekw = {
      score.first - points[iteration[{a, b}] - 1].first,
      score.second - points[iteration[{a, b}] - 1].second};
  score.first += kekw.first * (k / sz);
  score.second += kekw.second * (k / sz);
  k %= sz;
  while (k) {
    long long t = play(a, b);
    if (t == -1) score.second++;
    if (t == 1) score.first++;
    long long a1 = alice[{a, b}];
    long long b1 = bob[{a, b}];
    a = a1, b = b1;
    k--;
  }
  cout << score.first << " " << score.second << endl;
}
