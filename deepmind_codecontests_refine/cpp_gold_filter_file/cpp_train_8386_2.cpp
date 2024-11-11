#include <bits/stdc++.h>
using namespace std;
pair<int, int> edge[100001];
int n, m, k, x, y;
bool centre[1001];
int r[1001], parent[1001], set_size[1001];
void init(int n) {
  for (int i = 0; i < (int)(n); i++) {
    r[i] = 0;
    parent[i] = i;
    set_size[i] = 1;
    centre[i] = false;
  }
}
int findset(int i) {
  return parent[i] == i ? i : parent[i] = findset(parent[i]);
}
void unionset(int a, int b) {
  x = findset(a), y = findset(b);
  if (x == y) return;
  if (r[x] != r[y])
    if (r[x] > r[y])
      set_size[x] += set_size[y], parent[y] = x;
    else
      set_size[y] += set_size[x], parent[x] = y;
  else
    r[x]++, set_size[x] += set_size[y], parent[y] = x;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  init(n);
  for (int i = 0; i < (int)(k); i++)
    cin >> x, --x, centre[x] = true, r[x] = 5000;
  for (int i = 0; i < (int)(m); i++)
    cin >> x >> y, edge[i] = make_pair(x - 1, y - 1);
  for (int i = 0; i < (int)(m); i++) unionset(edge[i].first, edge[i].second);
  long long int ans = 0;
  int m_size = -1, m_comp = -1;
  for (int i = 0; i < (int)(n); i++)
    if (findset(i) == i and centre[i] and set_size[i] > m_size)
      m_size = set_size[i], m_comp = i;
  long long int temp = 0, num = 0;
  for (int i = 0; i < (int)(n); i++) {
    if (i == m_comp or (!centre[i] and findset(i) == i)) {
      num += set_size[i];
    } else if (centre[i]) {
      ans += (set_size[i] * (set_size[i] - 1)) / 2LL;
    }
  }
  ans += (num * (num - 1) / 2LL);
  ans -= m;
  cout << ans, cout << "\n";
  return 0;
}
