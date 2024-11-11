#include <bits/stdc++.h>
using namespace std;
long long all, f[1000050], sum[1000050];
pair<long long, long long> area[1000050];
map<long long, long long> Q;
int Rand() { return (rand() << 15) | rand(); }
long long Mod(long long ask) { return (ask % all + all) % all; }
int main() {
  long long n, g, r, q, number, pos, temp, i, answer;
  map<long long, long long>::iterator it;
  srand((unsigned)time(0));
  scanf("%I64d%I64d%I64d", &n, &g, &r);
  all = g + r;
  for (i = 1; i <= n + 1; i++) {
    scanf("%I64d", &sum[i]);
    sum[i] += sum[i - 1];
    area[i] = make_pair(Mod(-sum[i]), Mod(g - sum[i] - 1));
  }
  Q[g + r - 1] = n + 1;
  for (i = n; i >= 1; i--) {
    it = Q.lower_bound(area[i].first);
    if (it == Q.end()) {
      it = Q.lower_bound(0);
    }
    number = it->second;
    if (number == n + 1) {
      f[i] = sum[number] - sum[i];
    } else {
      f[i] = sum[number] - sum[i] + f[number] +
             Mod(area[number].first - area[i].first);
    }
    int kk = Q.size();
    int aaa = 1;
    if (area[i].first <= area[i].second) {
      while (area[i].first > 0) {
        it = Q.lower_bound(0);
        if (it == Q.end() || it->first >= area[i].first) {
          break;
        }
        Q.erase(it);
      }
      if (area[i].first > 0) {
        Q[area[i].first - 1] = i;
      }
      it = Q.upper_bound(area[i].second);
      if (it != Q.end()) {
        if (Q.find(area[i].second) == Q.end()) {
          Q[area[i].second] = it->second;
        }
        Q.erase(it);
      }
      while (area[i].second < g + r - 1) {
        it = Q.upper_bound(area[i].second);
        if (it == Q.end()) {
          break;
        }
        Q.erase(it);
      }
      if (area[i].second < g + r - 1) {
        Q[g + r - 1] = i;
      }
    } else {
      it = Q.upper_bound(area[i].second);
      if (it != Q.end()) {
        if (Q.find(area[i].second) == Q.end()) {
          Q[area[i].second] = it->second;
        }
        if (it->first <= area[i].first - 1) {
          Q.erase(it);
        }
      }
      while (true) {
        it = Q.upper_bound(area[i].second);
        if (it == Q.end() || it->first >= area[i].first) {
          break;
        }
        Q.erase(it);
      }
      Q[area[i].first - 1] = i;
    }
  }
  scanf("%I64d", &q);
  for (i = 1; i <= q; i++) {
    scanf("%I64d", &temp);
    pos = Mod(temp);
    it = Q.lower_bound(pos);
    number = it->second;
    answer = temp + sum[number] + f[number];
    if (number <= n) {
      answer += Mod(area[number].first - pos);
    }
    printf("%I64d\n", answer);
  }
  return 0;
}
