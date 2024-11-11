#include <bits/stdc++.h>
using namespace std;
const int N = 123456;
struct Leg {
  int len, energy;
} t[N];
int cntlen[N], cntenergy[N];
priority_queue<int> pq;
int need(int ctr) {
  vector<int> v;
  int ans = 0;
  while (!pq.empty() && ctr--) {
    v.push_back(pq.top());
    ans += pq.top();
    pq.pop();
  }
  for (int i = 0; i < v.size(); i++) {
    pq.push(v[i]);
  }
  return ans;
}
bool compare(Leg a, Leg b) {
  if (a.len == b.len) {
    return (a.energy < b.energy);
  } else {
    return a.len < b.len;
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &t[i].len);
    cntlen[t[i].len]++;
  }
  int total = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &t[i].energy);
    cntenergy[t[i].len] += t[i].energy;
    total += t[i].energy;
  }
  sort(t, t + n, compare);
  int res = (int)2e9;
  for (int i = 0; i < n; i += cntlen[t[i].len]) {
    int f = need(cntlen[t[i].len] - 1);
    res = min(res, total - f - cntenergy[t[i].len]);
    for (int j = i; j < cntlen[t[i].len]; j++) {
      pq.push(t[i].energy);
    }
  }
  printf("%d\n", res);
}
