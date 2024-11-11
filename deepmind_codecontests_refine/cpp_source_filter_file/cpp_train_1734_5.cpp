#include <bits/stdc++.h>
using namespace std;
int N;
int A[100010];
vector<int> B;
vector<int> sol, cum;
void dfs(int k) {
  if (k >= 18) return;
  if (sol.size() >= 19) return;
  sort(B.begin(), B.end());
  B.resize(unique(B.begin(), B.end()) - B.begin());
  if (B.size() == 1 && B[0] == 0) {
    if (sol.size() == 0 || sol.size() > cum.size()) {
      sol = cum;
    }
    return;
  }
  bool ok = false;
  for (int i = 0; i < B.size(); i++) {
    if (abs(B[i]) & 1) {
      ok = true;
      break;
    }
  }
  if (ok) {
    vector<int> tmp = B;
    for (int i = 0; i < B.size(); i++) {
      if (abs(B[i]) & 1) B[i]--;
      B[i] /= 2;
    }
    cum.push_back(1 << k);
    dfs(k + 1);
    cum.pop_back();
    B = tmp;
    for (int i = 0; i < B.size(); i++) {
      if (abs(B[i]) & 1) B[i]++;
      B[i] /= 2;
    }
    cum.push_back(-(1 << k));
    dfs(k + 1);
    cum.pop_back();
  } else {
    for (int i = 0; i < B.size(); i++) {
      B[i] /= 2;
    }
    dfs(k + 1);
  }
}
int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }
  for (int i = 0; i < N; i++) {
    B.push_back(A[i]);
  }
  dfs(0);
  printf("%d\n", sol.size());
  for (int i = 0; i < sol.size(); i++) {
    printf("%d ", sol[i]);
  }
}
