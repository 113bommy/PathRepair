#include <bits/stdc++.h>
using namespace std;
int N, M;
int cells[1010][1010];
bool check(int a, int b) {
  if (cells[a - 1][b - 1] && cells[a][b - 1] && cells[a][b - 1]) return true;
  if (cells[a - 1][b] && cells[a][b + 1] && cells[a - 1][b + 1]) return true;
  if (cells[a][b - 1] && cells[a + 1][b - 1] && cells[a + 1][b]) return true;
  if (cells[a + 1][b] && cells[a + 1][b + 1] && cells[a][b + 1]) return true;
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  scanf("%d", &N);
  scanf("%d", &M);
  int K;
  scanf("%d", &K);
  int ans = 0;
  int flag = 0;
  for (int i = 1; i <= K; i++) {
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    cells[a][b] = 1;
    if (flag == 0 && check(a, b)) {
      ans = i;
      flag = 1;
    }
  }
  cout << ans << endl;
  return 0;
}
