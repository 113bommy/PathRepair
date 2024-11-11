#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;
int n, m, dx, dy;
pair<int, int> apples[MAX];
int tmp[MAX];
int main() {
  scanf("%d %d %d %d", &n, &m, &dx, &dy);
  for (int i = int(0); i < int(m); i++) {
    scanf("%d %d", &apples[i].first, &apples[i].second);
  }
  map<int, int> mpx, backx;
  int v = 0, cnt = 0;
  for (int i = int(0); i < int(n); i++) {
    backx[cnt] = v;
    mpx[v] = cnt++;
    v = (v + dx) % n;
  }
  map<int, int> mpy, backy;
  v = 0, cnt = 0;
  for (int i = int(0); i < int(n); i++) {
    backy[cnt] = v;
    mpy[v] = cnt++;
    v = (v + dy) % n;
  }
  int best = 0;
  pair<int, int> start;
  map<int, int> diff;
  for (int i = int(0); i < int(m); i++) {
    apples[i].first = mpx[apples[i].first];
    apples[i].second = mpy[apples[i].second];
    int d = (apples[i].first < apples[i].second)
                ? (apples[i].first + n) - apples[i].second
                : apples[i].first - apples[i].second;
    diff[d]++;
    if (diff[d] > best) {
      best = diff[d];
      start = pair<int, int>(apples[i].first, apples[i].second);
    }
  }
  printf("%d %d\n", backx[start.first], backy[start.second]);
  return 0;
}
