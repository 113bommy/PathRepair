#include <bits/stdc++.h>
using namespace std;
int N;
int P[1010101];
signed long long dif[1010101];
signed long long sum[1010101];
signed long long V[1010101];
void solve() {
  int i, j, k, l, r, x, y;
  string s;
  scanf("%d", &N);
  for (i = 0; i < (N); i++) {
    scanf("%d", &P[i]), P[i]--;
    V[0] += abs(P[i] - i);
    if (P[i] == i) {
      dif[0]++;
      sum[N - i] -= N - P[i];
      sum[N - i] += P[i];
      dif[N - i + 1]--;
      dif[N - i + 1]--;
    } else if (P[i] > i) {
      dif[0]--;
      dif[P[i] - i + 1]++;
      dif[P[i] - i + 1]++;
      sum[N - i] -= N - P[i];
      sum[N - i] += P[i];
      dif[N - i]--;
      dif[N - i]--;
    } else {
      dif[0]++;
      dif[N - i + 1]--;
      dif[N - i + 1]--;
      sum[N - i] -= N - P[i];
      sum[N - i] += P[i];
      dif[N + P[i] - i + 1]++;
      dif[N + P[i] - i + 1]++;
    }
  }
  signed long long shi = 0, ret = V[0];
  for (i = 1; i < N; i++) {
    dif[i] += dif[i - 1];
    V[i] += V[i - 1] + dif[i] + sum[i];
    if (V[i] < ret) shi = i, ret = V[i];
  }
  cout << ret << " " << shi << endl;
}
int main(int argc, char** argv) {
  string s;
  int i;
  if (argc == 1) ios::sync_with_stdio(false), cin.tie(0);
  for (i = 0; i < (argc - 1); i++) s += argv[i + 1], s += '\n';
  for (i = 0; i < (s.size()); i++) ungetc(s[s.size() - 1 - i], stdin);
  solve();
  return 0;
}
