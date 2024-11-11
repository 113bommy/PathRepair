#include <bits/stdc++.h>
using namespace std;
int h, w, n;
struct data {
  int x_1, y_1, x_2, y_2;
};
vector<data> v;
int A[20005];
void area(int x, int y) {
  int g_x = w;
  int g_y = h;
  int m_x = 0;
  int m_y = 0;
  for (auto it : v) {
    if (it.y_1 == it.y_2) {
      if (y <= it.y_1 and x >= it.x_1 and x <= it.x_2) g_y = min(g_y, it.y_1);
      if (y > it.y_1 and x >= it.x_1 and x <= it.x_2) m_y = max(m_y, it.y_1);
    }
    if (it.x_1 == it.x_2) {
      if (x <= it.x_1 and y >= it.y_1 and y <= it.y_2) g_x = min(g_x, it.x_1);
      if (x > it.x_1 and y >= it.y_1 and y <= it.y_2) m_x = max(m_x, it.x_1);
    }
  }
  A[(g_x - m_x) * (g_y - m_y)] += 1;
}
int main() {
  scanf("%d %d %d", &w, &h, &n);
  v.push_back({0, 0, w, 0});
  v.push_back({0, 0, 0, h});
  v.push_back({w, 0, w, h});
  v.push_back({0, h, w, h});
  for (int i = 0; i < n; ++i) {
    int x_1, y_1, x_2, y_2;
    scanf("%d %d %d %d", &x_1, &y_1, &x_2, &y_2);
    if (x_1 > x_2) swap(x_1, x_2);
    if (y_1 > y_2) swap(y_1, y_2);
    v.push_back({x_1, y_1, x_2, y_2});
  }
  for (int i = 1; i <= w; ++i)
    for (int j = 1; j <= h; ++j) area(i, j);
  for (int i = 1; i <= w * h; ++i)
    for (int j = 0; j * i < A[i]; ++j) printf("%d ", i);
  puts("");
  return 0;
}
