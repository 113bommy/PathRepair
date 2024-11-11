#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
constexpr int SQ = 350;
int n, a, c, pos[N];
deque<int> block[SQ], mono[SQ];
void add(int val, int p) {
  block[p].push_front(val);
  while (!mono[p].empty() && mono[p].back() < val) mono[p].pop_back();
  mono[p].push_back(val);
}
void rem(int p) {
  int v = block[p].back();
  block[p].pop_back();
  if (mono[p].front() == v) mono[p].pop_front();
}
void relax(int val, int p, int have) {
  block[p].push_back(val);
  for (int i = (int)block[p].size() - 2; ~i; i--) {
    if (!have) break;
    if (block[p][i] < block[p][i + 1]) {
      swap(block[p][i], block[p][i + 1]);
      have--;
    } else
      break;
  }
  mono[p].clear();
  for (int i = (int)block[p].size() - 1; ~i; i--) {
    while (!mono[p].empty() && mono[p].back() < block[p][i]) mono[p].pop_back();
    mono[p].push_back(block[p][i]);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> c;
    pos[a] = i + 1;
    int sz = (int)block[i / SQ].size();
    if (sz >= c || !(i / SQ) ||
        (!mono[i / SQ].empty() && mono[i / SQ].front() > a) ||
        block[i / SQ - 1].back() > a) {
      relax(a, i / SQ, c);
      continue;
    }
    for (int j = i / SQ - 1; ~j; j--) {
      sz += (int)block[j].size();
      add(block[j].back(), j + 1);
      rem(j);
      if (sz >= c || !j || mono[j].front() > a || block[j - 1].back() > a) {
        relax(a, j, c - sz + (int)block[j].size());
        break;
      }
    }
  }
  for (int i = 0; i <= (n - 1) / SQ; i++)
    for (auto j : block[i]) cout << j << ' ';
  cout << '\n';
  return 0;
}
