#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000001;
const double EPS = 10e-9;
int const S = 1 << 19;
int n, a[S], leftlink[S], rightlink[S], decrease;
pair<int, int> tree[2 * S];
pair<int, int> Min() { return tree[1]; }
void Init() {
  tree[S] = make_pair(INF, 0);
  for (int i = 1; i <= (n); ++i) tree[i + S] = make_pair(a[i], i);
  for (int i = n + 1; i <= (S - 1); ++i) tree[S + i] = make_pair(INF, i);
  for (int i = S - 1; i >= (1); --i)
    tree[i] = min(tree[2 * i], tree[2 * i + 1]);
}
void Delete(int p) {
  for (tree[p + S] = make_pair(INF, p), p += S, p >>= 1; p; p >>= 1)
    tree[p] = min(tree[p * 2], tree[p * 2 + 1]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= (n); ++i) {
    cin >> a[i];
    leftlink[i] = i - 1;
    rightlink[i] = i + 1;
  }
  rightlink[n] = 0;
  Init();
  pair<int, int> greedy;
  long long ans = 0;
  while (n) {
    if (n == 2) break;
    greedy = Min();
    Delete(greedy.second);
    if (!leftlink[greedy.second]) {
      ans += ((long long)(n - 2)) * (greedy.first - decrease);
      leftlink[rightlink[greedy.second]] = 0;
      decrease = greedy.first;
      --n;
      continue;
    }
    if (!rightlink[greedy.second]) {
      ans += ((long long)(n - 2)) * (greedy.first - decrease);
      decrease = greedy.first;
      rightlink[leftlink[greedy.second]] = 0;
      --n;
      continue;
    }
    leftlink[rightlink[greedy.second]] = leftlink[greedy.second];
    rightlink[leftlink[greedy.second]] = rightlink[greedy.second];
    ans +=
        min(a[leftlink[greedy.second]], a[rightlink[greedy.second]]) - decrease;
    --n;
  }
  cout << ans;
  return 0;
}
