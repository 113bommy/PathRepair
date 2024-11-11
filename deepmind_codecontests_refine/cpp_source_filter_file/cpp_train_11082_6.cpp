#include <bits/stdc++.h>
using namespace std;
struct thing {
  int L;
  int R;
  int V;
  bool operator<(const thing &th) const {
    if (V > th.V || (V == th.V && L > th.L)) return true;
    return false;
  }
} in;
priority_queue<thing> work;
int N, give;
bool b[200010];
int v[200010];
bool ed[200010];
int L[200010];
int R[200010];
int main() {
  cin >> N;
  getchar();
  for (int i = 1; i <= N; i++)
    if (getchar() == 'B') {
      b[i] = true;
      give++;
    }
  give = min(give, N - give);
  cout << give << endl;
  for (int i = 1; i <= N; i++) scanf("%d", &v[i]);
  for (int i = 1; i <= N; i++) {
    L[i] = i - 1;
    R[i] = i + 1;
  }
  for (int i = 1; i < N; i++) {
    if (b[i] == b[i + 1]) continue;
    in.L = i;
    in.R = i + 1;
    in.V = abs(v[i] - v[i + 1]);
    work.push(in);
  }
  while (give--) {
    in = work.top();
    work.pop();
    while (ed[in.L] || ed[in.R]) {
      in = work.top();
      work.pop();
    }
    printf("%d %d\n", in.L, in.R);
    ed[in.L] = true;
    ed[in.R] = true;
    L[R[in.R]] = L[in.L];
    R[L[in.L]] = R[in.R];
    if (L[in.L] >= 1 && R[in.R] <= N && b[L[in.L]] != b[R[in.R]]) {
      in.L = L[in.L];
      in.R = R[in.R];
      in.V = abs(v[L[in.L]] - v[R[in.R]]);
      work.push(in);
    }
  }
  return 0;
}
