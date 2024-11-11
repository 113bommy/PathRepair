#include <bits/stdc++.h>
using namespace std;
long long int cox[101011][105];
long long int box[100011][105];
long long int aox[100011];
void ini() {
  for (int i = 0; i <= 101000; i++) cox[i][0] = 1;
  for (int j = 1; j <= 103; j++)
    for (int i = j; i <= 101000; i++)
      cox[i][j] = (cox[i - 1][j - 1] + cox[i - 1][j]) % 1000000007;
}
int main() {
  ios::sync_with_stdio(0);
  ini();
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> aox[i];
  for (int i = 1; i <= m; i++) {
    int l, r, k;
    cin >> l >> r >> k;
    for (int j = 1; j <= k; j++)
      box[r + 1][j] =
          (box[r + 1][j] - cox[r - l + k - j + 1][k - j + 1] + 1000000007) %
          1000000007;
    box[l][k + 1] = (box[l][k + 1] + 1) % 1000000007;
    box[r + 1][k + 1] = (box[r + 1][k + 1] - 1 + 1000000007) % 1000000007;
  }
  for (int i = 101; i >= 1; i--) {
    long long int sum = 0;
    for (int j = 1; j <= n; j++) {
      sum += box[j][i];
      sum %= 1000000007;
      box[j][i - 1] += sum;
      box[j][i - 1] %= 1000000007;
    }
  }
  for (int i = 1; i <= n; i++) {
    aox[i] += box[i][0];
    aox[i] %= 1000000007;
  }
  for (int i = 1; i <= n; i++) cout << aox[i] << " ";
  cout << endl;
  return 0;
}
