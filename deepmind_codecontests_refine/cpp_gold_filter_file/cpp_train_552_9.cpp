#include <bits/stdc++.h>
using namespace std;
struct SCORE {
  int p, t;
};
bool operator<(const SCORE &a, const SCORE &b) {
  if (a.p == b.p) return a.t < b.t;
  return a.p > b.p;
}
bool operator==(const SCORE &a, const SCORE &b) {
  return a.p == b.p && a.t == b.t;
}
const int N = 55;
SCORE s[N];
int place[N], ip[N];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d%d", &s[i].p, &s[i].t);
  sort(s, s + n);
  for (int i = 0; i < n; i++) {
    place[i] = i + 1;
    if (i > 0 && s[i] == s[i - 1]) place[i] = place[i - 1];
  }
  for (int i = 0; i < n; i++) ip[n - i - 1] = place[i];
  printf("%d", count(place, place + n,
                     ip[lower_bound(ip, ip + n, k, greater<int>()) - ip]));
}
