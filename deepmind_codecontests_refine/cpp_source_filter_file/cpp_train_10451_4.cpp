#include <bits/stdc++.h>
using namespace std;
const int NMax = 3000;
bool cmp(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
int N;
pair<int, int> A[NMax];
int can[NMax], limit[NMax], ret[NMax];
int cross(pair<int, int> a, pair<int, int> b) {
  if (a == b) return 0;
  if (a.first < b.second && a.first > b.first) return 1;
  if (a.second < b.second && a.second > b.first) return 1;
  if (b.first < a.second && b.first > a.first) return 1;
  if (b.second < a.second && b.second > a.first) return 1;
  return 0;
}
int sum[NMax];
int calc(int a) {
  for (int i = 1; i <= N; i++) {
    can[i] = 1;
    limit[i] = N;
    ret[i] = -1;
  }
  for (int i = 1; i <= N; i++) {
    memset(sum, 0, sizeof(sum));
    int choose = -1;
    for (int j = 1; j <= N; j++)
      if (can[j] && ret[j] == -1 &&
          (choose == -1 || A[j].second < A[choose].second)) {
        choose = j;
      }
    ret[choose] = i;
    for (int j = 1; j <= N; j++)
      if (ret[j] == -1 && cross(A[choose], A[j])) {
        limit[j] = min(limit[j], i + a);
      }
    for (int j = 1; j <= N; j++)
      if (ret[j] == -1) sum[limit[j]]++;
    for (int j = 1; j <= N + 1; j++) sum[j] += sum[j - 1];
    for (int j = i + 1; j <= N; j++)
      if (j - i < sum[j]) return 0;
    int go = N + 1;
    for (int j = i + 1; j <= N; j++) {
      if (j - i == sum[j]) {
        go = j;
        break;
      }
    }
    for (int j = 1; j <= N; j++) can[j] = (ret[j] == -1 && limit[j] <= go);
  }
  return 1;
}
int Ans[NMax];
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) scanf("%d%d", &A[i].first, &A[i].second);
  int l = 0, r = N + 1;
  while (l < r) {
    if (l + 1 == r) break;
    int mid = (l + r) >> 1;
    if (calc(mid))
      r = mid;
    else
      l = mid;
  }
  calc(r);
  for (int i = 1; i <= N; i++) Ans[ret[i]] = i;
  for (int i = 1; i <= N; i++) printf("%d ", Ans[i]);
  puts("");
  return 0;
}
