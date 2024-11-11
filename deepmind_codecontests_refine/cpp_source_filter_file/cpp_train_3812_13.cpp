#include <bits/stdc++.h>
using namespace std;
struct s {
  int x, y[5];
} st;
bool operator<(const s &a, const s &b) { return a.x < a.x; }
int n, x[1005][5], ta;
vector<s> v;
vector<int> ans;
bool o;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 5; j++) scanf("%d", x[i] + j);
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      st.x = 0;
      for (int k = 0; k < 5; k++) {
        st.x += ((x[i][k] - x[j][k]) * (x[i][k] - x[j][k]));
        st.y[k] = x[i][k] + x[j][k];
      }
      v.push_back(st);
    }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    o = 1;
    for (int j = 0; j < v.size(); j++) {
      ta = 0;
      for (int k = 0; k < 5; k++)
        ta += ((v[j].y[k] - x[i][k] * 2) * (v[j].y[k] - x[i][k] * 2));
      if (ta > v[j].x * 4) {
        o = 0;
        break;
      }
    }
    if (o) ans.push_back(i);
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++)
    printf("%d%c", ans[i] + 1, i == ans.size() - 1 ? '\n' : ' ');
  return 0;
}
