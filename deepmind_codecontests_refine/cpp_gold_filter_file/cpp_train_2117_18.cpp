#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
int id[111111], ID[111111], S[111111], F[111111], L[111111], R[111111],
    T[111111], B[111111];
int ans[111111];
int arr[4 * 111111];
set<int> mx[4 * 111111];
bool cmp(int i, int j) { return L[i] < L[j]; }
bool cmp1(int i, int j) { return S[i] < S[j]; }
void update(int u, int val) {
  while (u) {
    mx[u].insert(val);
    u -= u & (-u);
  }
}
set<int>::iterator it;
int calc(int u, int val) {
  int ans = 0x3f3f3f3f;
  while (u < 4 * 111111) {
    it = mx[u].lower_bound(val);
    if (it != mx[u].end()) {
      ans = min(ans, *it);
    }
    u += u & (-u);
  }
  return ans;
}
int main() {
  int N, M;
  scanf("%d %d", &N, &M);
  int nn = 0;
  for (int i = 0; i < N; i++) {
    scanf("%d %d %d", S + i, F + i, T + i);
    ID[i] = i;
    mp[T[i]] = i + 1;
    arr[nn++] = F[i], arr[nn++] = S[i];
  }
  for (int i = 0; i < M; i++) {
    id[i] = i;
    scanf("%d %d %d", L + i, R + i, B + i);
    arr[nn++] = R[i], arr[nn++] = L[i];
  }
  sort(arr, arr + nn);
  nn = unique(arr, arr + nn) - arr;
  for (int i = 0; i < N; i++) S[i] = upper_bound(arr, arr + nn, S[i]) - arr;
  for (int i = 0; i < N; i++) F[i] = upper_bound(arr, arr + nn, F[i]) - arr;
  for (int i = 0; i < M; i++) L[i] = upper_bound(arr, arr + nn, L[i]) - arr;
  for (int i = 0; i < M; i++) R[i] = upper_bound(arr, arr + nn, R[i]) - arr;
  sort(id, id + M, cmp);
  sort(ID, ID + N, cmp1);
  int cur = 0;
  for (int ii = 0; ii < M; ii++) {
    int i = id[ii];
    while (cur < N && S[ID[cur]] <= L[i]) update(F[ID[cur]], T[ID[cur]]), cur++;
    ans[i] = calc(R[i], B[i]);
    if (ans[i] == 0x3f3f3f3f)
      ans[i] = -1;
    else
      ans[i] = mp[ans[i]];
  }
  for (int i = 0; i < M; i++) printf("%d\n", ans[i]);
  return 0;
}
