#include <bits/stdc++.h>
using namespace std;
int data[110][110], answer[110], block[110];
bool used[110];
int main() {
  int N, M, K;
  cin >> N >> M >> K;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) cin >> data[i][j];
  }
  for (int j = 1; j <= M; j++) {
    for (int k = 0; k < 110; k++) used[k] = 0;
    for (int i = 1; i <= N; i++) {
      if (answer[i] || !data[i][j]) continue;
      if (block[data[i][j]]) {
        answer[i] = j;
        continue;
      }
      if (used[data[i][j]]) {
        block[data[i][j]] = 1;
        answer[i] = answer[used[data[i][j]]] = j;
      } else {
        used[data[i][j]] = i;
      }
    }
  }
  for (int i = 1; i <= N; i++) cout << answer[i] << endl;
  return 0;
}
