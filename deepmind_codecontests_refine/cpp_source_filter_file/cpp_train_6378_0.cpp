#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, m;
int a[maxn];
pair<int, int> state[maxn];
int block;
int lastEl[maxn];
int main() {
  cin >> n >> m;
  block = sqrt(n) + 1;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  int dis;
  for (int i = n - 1; i >= 0; i--) {
    dis = i + a[i];
    if (dis >= n) {
      state[i].first = -1;
      state[i].second = 1;
      lastEl[i] = i;
    } else if (dis / block > i / block) {
      state[i].first = dis;
      state[i].second = 1;
      lastEl[i] = i;
    } else {
      state[i].first = state[dis].first;
      state[i].second = state[dis].second + 1;
      lastEl[i] = lastEl[dis];
    }
  }
  while (m--) {
    int det;
    scanf("%d", &det);
    if (det == 0) {
      int el, pow;
      scanf("%d", &el);
      scanf("%d", &pow);
      el--;
      a[el] = pow;
      int dis;
      int blockStart = (el / block) * block;
      for (int i = el; i >= blockStart; i--) {
        dis = i + a[i];
        if (i != el && dis > el) continue;
        if (dis >= n) {
          state[i].first = -1;
          state[i].second = 1;
          lastEl[i] = i;
        } else if (dis / block > i / block) {
          state[i].first = dis;
          state[i].second = 1;
          lastEl[i] = i;
        } else {
          state[i].first = state[dis].first;
          state[i].second = state[dis].second + 1;
          lastEl[i] = lastEl[dis];
        }
      }
    } else {
      int el;
      scanf("%d", &el);
      el--;
      int ans = 0;
      int last;
      while (el != -1) {
        last = el;
        ans += state[el].second;
        el = state[el].first;
      }
      printf("%d %d \n", lastEl[last] + 1, ans);
    }
  }
  return 0;
}
