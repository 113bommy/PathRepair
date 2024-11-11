#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 1e3;
const double eps = 1e-5;
int arr[maxN];
int INPUT() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int main() {
  int N = INPUT();
  for (int i = 1; i <= N; ++i) {
    arr[i] = INPUT();
  }
  for (int i = 1; i <= N; ++i) {
    if (arr[i] < 0) {
      goto Fail;
    }
    if (arr[i] % 2 == 1) {
      --arr[i + 1];
    }
  }
  cout << "YES" << endl;
  goto End;
Fail:
  cout << "NO" << endl;
End:
  return 0;
}
