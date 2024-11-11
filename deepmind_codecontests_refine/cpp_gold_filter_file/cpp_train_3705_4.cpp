#include <bits/stdc++.h>
using namespace std;
vector<int> Ans1, Ans2, has;
int query(int x, int y) {
  cout << 0 << ' ' << x << ' ' << y << endl;
  fflush(stdout);
  int t;
  scanf("%d", &t);
  return t;
}
void solve(int l, int r) {
  if (l > r) return;
  int M = l + r >> 1;
  int d = query(M, M);
  if (!d) {
    has.push_back(M);
    d = 1;
  }
  solve(l, M - d);
  solve(M + d, r);
}
void Work() {
  int blk = 1e8;
  sort(has.begin(), has.end());
  for (int i = 0; i < has.size() - 1; i++)
    if (has[i] + 1 != has[i + 1]) blk = has[i] + 1;
  for (auto i : has) {
    if (!query(i, blk)) Ans1.push_back(i);
    if (!query(blk, i)) Ans2.push_back(i);
  }
  cout << 1 << ' ' << Ans1.size() << ' ' << Ans2.size() << endl;
  for (auto i : Ans1) cout << i << ' ';
  cout << endl;
  for (auto i : Ans2) cout << i << ' ';
  cout << endl;
  fflush(stdout);
}
void Init() { solve(-1e8, 1e8); }
int main() {
  Init();
  Work();
  return 0;
}
