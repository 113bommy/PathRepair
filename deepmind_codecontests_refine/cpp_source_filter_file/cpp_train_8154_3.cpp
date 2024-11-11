#include <bits/stdc++.h>
using namespace std;
long long Ans = -1e9;
long long temp = 0;
int N, U, R;
int a[55][55];
int b[55];
int k[55];
int p[55];
void Find(int depth, int prev) {
  int i;
  temp = 0;
  for (int i = 1; i <= N; ++i) {
    temp += a[depth][i] * k[i];
  }
  if ((U - depth) % 2 == 0) {
    Ans = max(Ans, temp);
  }
  if (depth == U) {
    return;
  }
  for (int i = 1; i <= N; ++i) {
    a[depth + 1][i] = a[depth][p[i]] + R;
  }
  Find(depth + 1, 0);
  if (prev == 1) {
    return;
  }
  for (int i = 1; i <= N; ++i) {
    a[depth + 1][i] = a[depth][i] ^ b[i];
  }
  Find(depth + 1, 1);
}
int main() {
  cin >> N >> U >> R;
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &a[0][i]);
  }
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &b[i]);
  }
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &k[i]);
  }
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &p[i]);
  }
  Find(0, 0);
  cout << Ans << endl;
  return 0;
}
