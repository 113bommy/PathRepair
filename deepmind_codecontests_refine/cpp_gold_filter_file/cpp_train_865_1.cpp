#include <bits/stdc++.h>
using namespace std;
const int oo = 1 << 20;
const double PI = M_PI;
const double EPS = 1e-15;
const int MaxN = 100006;
int N, M, C;
int a[MaxN];
int b[MaxN];
int main() {
  cin.sync_with_stdio(false);
  cin >> N >> M >> C;
  for (int i = 1; i <= (N); i++) cin >> a[i];
  for (int i = 1; i <= (M); i++) cin >> b[i];
  for (int i = 1; i <= (M); i++) b[i] = (b[i] + b[i - 1]) % C;
  int last = N - M + 1;
  for (int i = 1; i <= (N); i++) {
    if (last < i)
      cout << (a[i] + b[min(i, M)] - b[i - last] + C) % C << " ";
    else
      cout << (a[i] + b[min(i, M)]) % C << " ";
  }
  return 0;
}
