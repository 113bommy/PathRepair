#include <bits/stdc++.h>
using namespace std;
constexpr int carry_minati = 1e5 + 100;
int n, d, f, c[carry_minati], ff[carry_minati], dd[carry_minati], res = 0,
                                                                  val = 0;
vector<int> g, a, b;
void tensor_flow() {
  g.clear();
  for (int i = 0; i < n; i++)
    if (c[i] == 0 and dd[i] >= d) g.push_back(ff[i]);
  sort(g.begin(), g.end());
  int ans = 0;
  for (int i = 0; i < g.size(); i++) {
    ans += g[i];
    if (ans > f) break;
    if (i + 1 > res or (i + 1 == res and ans < val)) {
      res = i + 1;
      val = ans;
    }
  }
  return;
}
void amit_bhadana() {
  bool can = 0;
  for (int i = 0; i < n; i++)
    if (c[i] and ff[i] <= f and dd[i] >= d) can = 1;
  if (!can) return;
  int hi = 0;
  for (int i = 0; i < n; i++) {
    hi += c[i];
    hi = min(hi, n);
  }
  for (int i = 0; i < n; i++)
    if (dd[i] >= d)
      if (c[i])
        a.push_back(ff[i]);
      else
        b.push_back(ff[i]);
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int answer = a[0], i = 1, j = 0;
  while (1) {
    int cnt = min(i + j + hi, n);
    if (cnt > res or (cnt == res and answer < val)) {
      res = cnt;
      val = answer;
    }
    if (i == a.size() and j == b.size()) break;
    if (i < a.size() and (j == b.size() or a[i] < b[j])) {
      answer += a[i];
      i++;
    } else {
      answer += b[j];
      j++;
    }
    if (answer > f) break;
  }
}
int main() {
  cin >> n >> d >> f;
  for (int i = 0; i < n; i++) cin >> c[i] >> ff[i] >> dd[i];
  tensor_flow();
  amit_bhadana();
  cout << res << " " << val;
  return 0;
}
