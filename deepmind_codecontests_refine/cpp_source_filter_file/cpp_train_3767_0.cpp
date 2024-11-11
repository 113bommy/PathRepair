#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int sg[N * 2];
int operation(int a, int b) { return a + b; }
int query(int l, int r) {
  l += N;
  r += N + 1;
  int ans = 0;
  for (; l < r; l >>= 1, r >>= 1) {
    if (l & 1) ans = operation(ans, sg[l++]);
    if (r & 1) ans = operation(ans, sg[--r]);
  }
  return ans;
}
void actualizar(int position, int value) {
  sg[position + N] += value;
  for (int pos = (N + position) / 2; pos > 0; pos /= 2)
    sg[pos] = operation(sg[pos * 2], sg[pos * 2 + 1]);
}
int corrimiento = 5001;
int n;
vector<pair<int, pair<int, int>>> ver;
vector<pair<pair<int, int>, int>> hor;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    if (x1 == x2)
      ver.push_back(make_pair(
          x1 + corrimiento,
          make_pair(corrimiento + min(y1, y2), corrimiento + max(y1, y2))));
    else
      hor.push_back(make_pair(
          make_pair(corrimiento + max(x1, x2), corrimiento + min(x1, x2)),
          y1 + corrimiento));
  }
  sort(ver.begin(), ver.end());
  sort(hor.begin(), hor.end());
  memset(sg, 0, sizeof sg);
  int ans = 0;
  deque<pair<int, int>> aux;
  for (int i = 0; i < ver.size(); i++) {
    for (int j = 0; j < hor.size(); j++) {
      if (hor[j].first.second <= ver[i].first) {
        aux.push_back(make_pair(hor[j].second, hor[j].first.first));
        actualizar(hor[j].second, 1);
      }
    }
    for (int j = i + 1; j < ver.size(); j++) {
      while (aux.size() > 0 && aux[0].second < ver[j].first) {
        actualizar(aux[0].first, -1);
        aux.pop_front();
      }
      int x = query(max(ver[i].second.first, ver[j].second.first),
                    min(ver[i].second.second, ver[j].second.second));
      ans += ((x) * (x - 1)) / 2;
    }
    while (aux.size() > 0) {
      actualizar(aux[0].first, -1);
      aux.pop_front();
    }
  }
  cout << ans << endl;
  return 0;
}
