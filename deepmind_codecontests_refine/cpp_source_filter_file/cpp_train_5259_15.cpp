#include <bits/stdc++.h>
using namespace std;
int A[100005];
int len[100005];
int pos[100005];
int main() {
  int N;
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", A + i);
    pos[A[i]] = i;
  }
  int ans = N;
  len[N] = 1;
  for (int i = N - 1; i >= 1; i--) {
    int pos1 = pos[i];
    int nextpos = pos[i + 1];
    if (nextpos > pos1) {
      len[i] = len[i + 1] + 1;
    } else
      len[i] = 1;
    ans = min(ans, N - len[i]);
  }
  cout << ans << endl;
  return 0;
}
