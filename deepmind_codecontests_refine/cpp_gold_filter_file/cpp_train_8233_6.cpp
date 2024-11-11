#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 11, maxM = 15;
int N, M, A[maxM][maxN], pos[maxN][maxM], mark[maxN];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> N >> M;
  for (int i = 1; i <= M; i++)
    for (int j = 1; j <= N; j++) {
      cin >> A[i][j];
      pos[A[i][j]][i] = j;
    }
  long long ans = 0;
  for (int i = 1; i <= N; i++) {
    int val = A[1][i];
    if (mark[val]) continue;
    vector<int> v;
    int j = 0;
    bool stop;
    do {
      stop = false;
      for (int k = 1; k <= M; k++) {
        int p = pos[val][k] + j;
        if (p > N || A[k][p] != A[1][i + j]) {
          stop = true;
          break;
        }
      }
      if (!stop) v.push_back(A[1][i + j]);
      j++;
    } while (!stop);
    for (int i = 0; i < (int)v.size(); i++) {
      mark[v[i]] = 1;
      ans += (int)v.size() - i;
    }
  }
  cout << ans;
}
