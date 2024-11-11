#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
int kk[N];
int key[N];
pair<int, int> child[N];
pair<int, int> value[N];
long long tot[N];
long long cnt[N];
void buildAns(int root, int left, int right, long long sum, int depth) {
  if (child[root].first == 0) {
    for (int i = left; i < right; i++) tot[i] = sum, cnt[i] = depth;
    return;
  }
  int pos = lower_bound(kk + left, kk + right, key[root]) - kk;
  buildAns(child[root].first, left, pos, sum + value[root].second, depth + 1);
  buildAns(child[root].second, pos, right, sum + value[root].first, depth + 1);
}
int main() {
  int n;
  scanf("%d", &n);
  int root;
  for (int i = 1; i <= n; i++) {
    int f;
    scanf("%d%d", &f, &kk[i]);
    key[i] = kk[i];
    if (f == -1)
      root = i;
    else {
      if (child[f].first == 0)
        child[f].first = i;
      else
        child[f].second = i;
    }
  }
  for (int i = 1; i <= n; i++)
    if (key[child[i].first] > key[child[i].second])
      swap(child[i].first, child[i].second);
  sort(kk + 1, kk + 1 + n);
  for (int i = 1; i <= n; i++) {
    value[i].first = *(lower_bound(kk + 1, kk + 1 + n, key[i]) - 1);
    value[i].second = *upper_bound(kk + 1, kk + 1 + n, key[i]);
  }
  kk[0] = -2000000000;
  buildAns(root, 0, n + 1, 0, 0);
  int k;
  scanf("%d", &k);
  for (int i = 1; i <= k; i++) {
    int sk;
    scanf("%d", &sk);
    int pos = lower_bound(kk, kk + n + 1, sk) - kk - 1;
    printf("%.9f\n", tot[pos] * 1.0 / cnt[pos]);
  }
}
