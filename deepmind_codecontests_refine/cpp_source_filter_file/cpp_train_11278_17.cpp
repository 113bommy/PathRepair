#include <bits/stdc++.h>
using namespace std;
int last[30010];
int apply(int r, int a, int b, int m) {
  int ans = (((r * a) % m) + b) % m;
  return ans;
}
int main() {
  memset(last, -1, sizeof(last));
  int A, B, M, R0;
  cin >> A >> B >> M >> R0;
  int i, r;
  for (r = apply(R0, A, B, M), i = 0; last[r] == -1;
       r = apply(r, A, B, M), i++) {
    last[r] = i;
  }
  cout << (i - last[r]) << endl;
}
